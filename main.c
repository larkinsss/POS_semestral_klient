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

    Data data = {0};
    n = read(sockfd, &data, sizeof(Data));
    if (n > 0) {
        drawBoard();
    }


    mvprintw(13,0,"Please enter a message: ");
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
    close(sockfd);

    return 0;
}

void drawBoard()
{
    initscr();

    start_color();
    init_pair(1,COLOR_YELLOW, COLOR_BLACK);
    init_pair(2,COLOR_GREEN, COLOR_BLACK);
    init_pair(3,COLOR_BLUE, COLOR_BLACK);
    init_pair(4,COLOR_RED, COLOR_BLACK);

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