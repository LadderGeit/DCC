#if defined _dcc_included
    #endinput
#endif

#define _dcc_included

#include <amxmodx>

#pragma semicolon 1

new gDelayTask = 420;

/**
 * Sends a colored chat message.
 *
 * @note This function was created to allow delayed messages to be sent without the need for the user to set a task.
 *
 * @param playerIndex           Client index (use 0 to send to all players)
 * @param chatColor             The color used to begin the message with
 * @param Float:messageDelay    Delay in seconds
 * @param chatMessage           The message
 *
 * @noreturn
 */
stock DColorChat(const playerIndex, chatColor, Float:messageDelay = 0.0, const chatMessage[]) 
{
    if(!messageDelay)
    {
        client_print_color(playerIndex, chatColor, chatMessage);
        return;
    }

    if(!playerIndex)
    {
        new currentPlayer;
        new playerList[32], playerCount;
        get_players(playerList, playerCount);

        for(new i; i < playerCount; i++)
        {
            currentPlayer = playerList[i];

            if(!is_user_connected(currentPlayer))
                continue;

            set_task(messageDelay, "SendDelayedMessage", gDelayTask + currentPlayer);
        }

        return;
    }

    if(!is_user_connected(playerIndex))
        return;

    new messageInfo[64];
    formatex(messageInfo, charsmax(messageInfo), "%i ^"%s^"", chatColor, chatMessage);

    set_task(messageDelay, "SendDelayedMessage", gDelayTask + playerIndex, messageInfo, sizeof(messageInfo));
}

public SendDelayedMessage(const messageInfo[], taskIndex)
{
    new playerIndex = taskIndex - gDelayTask;
    gDelayTask++;

    if(!is_user_connected(playerIndex))
        return;
    
    new chatColor[2], chatMessage[64];
    parse(messageInfo, chatColor, charsmax(chatColor), chatMessage, charsmax(chatMessage));

    client_print_color(playerIndex, str_to_num(chatColor), chatMessage);
}