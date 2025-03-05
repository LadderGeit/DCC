#include <amxmodx>
#include <dcc>

public plugin_init() 
{
    register_clcmd("say /dcc", "TestDelayedMessage");
}

public TestDelayedMessage(id)
{
    new Float:messageDelay = 2.0;
    DColorChat(id, print_team_default, messageDelay, fmt("Printed message for ^3%i ^1after ^4%f seconds", id, messageDelay));
}