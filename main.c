#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>
#include "main.h"

int main(int argc, char *argv[])
{
    Data gameData;
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    char buffer[256];

    if (argc < 3)
    {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error, no such host\n");
        return 2;
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(
            (char*)server->h_addr,
            (char*)&serv_addr.sin_addr.s_addr,
            server->h_length
    );
    serv_addr.sin_port = htons(atoi(argv[2]));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 3;
    }

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to socket");
        return 4;
    }

    initscr();

    start_color();
    init_pair(1,COLOR_YELLOW, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);
    init_pair(3,COLOR_BLUE, COLOR_BLACK);
    init_pair(4,COLOR_RED, COLOR_BLACK);
    drawBoard();
    /*
     * SEM PRIDE FUNKCIONALITA HRY
     */

    GAME_DATA data;
    int reading;
    while (!data.endGame) {
        sleep(2);
        reading = read(sockfd, &data, sizeof(GAME_DATA));
        if (reading < 0 ) {
            perror("Error reading from socket");
        } else {
            redrawBoard(data);
            if (data.whosTurn == data.playerId) {
                mvprintw(15,0,"YOUR TURN>>");
                //TODO show options and let players select
                n = write(sockfd, &data, sizeof(GAME_DATA));
                if (n < 0)
                {
                    perror("Error writing to socket");
                    return 5;
                }
            }
        }
    }


    mvprintw(13,0,"Please enter a message: ");
    refresh();
    bzero(buffer,256);
    fgets(buffer, 255, stdin);

    n = write(sockfd, &data, strlen(buffer));
    if (n < 0)
    {
        perror("Error writing to socket");
        return 5;
    }

    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0)
    {
        perror("Error reading from socket");
        return 6;
    }

    printf("%s\n",buffer);


    /*
     * TU KONCI FUNKCIONALITA A ZATVARA SA SOCKET
     */
    close(sockfd);

    return 0;
}

void drawBoard()
{
    printw("        . . .        \n"
           "        .   .        \n"
           "        .   .        \n"
           "        .   .        \n"
           ". . . . .   . . . . .\n"
           ".                   .\n"
           ". . . . .   . . . . .\n"
           "        .   .        \n"
           "        .   .        \n"
           "        .   .        \n"
           "        . . .        \n");

    for (int player = 0; player < MAX_PLAYER_COUNT; ++player)
    {
        attron(COLOR_PAIR(colorFromPlayerNum(player)));

        // Printout pawns
        movePrintSpacing(playerPos[player][0][0], "1");
        movePrintSpacing(playerPos[player][0][1], "2");
        movePrintSpacing(playerPos[player][0][2], "3");
        movePrintSpacing(playerPos[player][0][3], "4");

        // Printout finish tiles
        for (int tile = 0; tile < PAWN_COUNT; ++tile) {
            movePrintSpacing(playerPos[player][1][tile], (const char *) (player % 2 == 0 ? "-" : "|"));
        }
        attroff(COLOR_PAIR(colorFromPlayerNum(player)));
    }

    refresh();
}

void redrawBoard(GAME_DATA data) {

    for (int player = 0; player < data.numberOfPlayers; ++player)
    {
        attron(COLOR_PAIR(colorFromPlayerNum(player)));

        // Printout pawns
        mvprintw(15,0,"Writing to pos: %d|%d", data.playerData->players[player][0].pos.x, data.playerData->players[player][0].pos.y);
        movePrintSpacing(data.playerData->players[player][0].pos, "1");
        mvprintw(16,0,"Writing to pos: %d|%d", data.playerData->players[player][1].pos.x, data.playerData->players[player][1].pos.y);
        movePrintSpacing(data.playerData->players[player][1].pos, "2");
        mvprintw(17,0,"Writing to pos: %d|%d", data.playerData->players[player][2].pos.x, data.playerData->players[player][2].pos.y);
        movePrintSpacing(data.playerData->players[player][2].pos, "3");
        mvprintw(18,0,"Writing to pos: %d|%d", data.playerData->players[player][3].pos.x, data.playerData->players[player][3].pos.y);
        movePrintSpacing(data.playerData->players[player][3].pos, "4");

        refresh();
        attroff(COLOR_PAIR(colorFromPlayerNum(player)));

    }
}

int movePrintSpacing(Position position, const char* string)
{
    return mvprintw(position.y, position.x * SPACING, string);
}

int getColor(enum Player player)
{
    return (int) player + 1;
}

int colorFromPlayerNum(int player)
{
    return player + 1;
}