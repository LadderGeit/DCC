<!-- 
Writing on GitHub Guidance: https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/quickstart-for-writing-on-github

- Styling text:
	- Bold:                			**Bold text**
	- Italic:              			*Italic text*
	- Strikethrough:				~~Strikethrough text~~
	- Bold and nested italic:		**Bold _Bold Italic_ text**
	- All bold and italic:			*** Bold Italic ***
	- Subscript:					<sub>Subscript text</sub>
	- Superscript:					<sup>Superscript text</super>
	- Underlined:					<ins>Underlined text</ins>

- Quoting text: >
 -->

> [!IMPORTANT]
> **Plugin compatibility**<br/>
> This plugin is only compatible with ***amxmodx 1.9 or higher.*** Support for older versions has been discontinued for ALL my plugins.<br/>
> - *Download [amxmodx 1.9](https://www.amxmodx.org/downloads-new.php) or [amxmodx 1.10](https://www.amxmodx.org/downloads-new.php?branch=master)*

# [DCC] Delayed ColorChat

![GitHub Created At](https://img.shields.io/github/created-at/LadderGeit/HitMarkers?style=plastic&color=blue)
![GitHub last commit](https://img.shields.io/github/last-commit/LadderGeit/HitMarkers?display_timestamp=committer&style=plastic&color=darkorange)

An easy to use include file that allows you send delayed chat messages to players

## Example
```c
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
```

## Changelog
<details>
<summary>Version list</summary>

- [ ] 1.0.0: Initial release [Current version]

</details>
