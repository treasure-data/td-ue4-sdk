# Treasure Data Analytics Plugin for Unreal Engine 4

This plugin behaves as an Analytics Provider for Unreal Engine 4.

## Requirements

- Unreal Engine 4.14
- [Treasure Data Write-Only API Key](https://console.treasuredata.com/users/current)

## Getting Started

The following document assumes that the current Unreal Engine have been compiled from sources or it have all dependencies so third party plugins can be build.

### Download and place the plugin

Get a copy of the plugin from the main GIT repository:

```
$ git glone http://github.com/treasure-data/td-ue4-sdk
```

Copy the new __td-ue4-sdk__ to your Engine plugins folder, the target path looks like:

```
UnrealEngine/Engine/Plugins/td-ue4-sdk
```
> Alternative you can copy the plugin content inside your Project Plugin directory, not that this approach don't work on Linux Development environment.

### Build the plugin

To build the plugin is required to generate the build-rules, for the purpose the UE4 Engine provides a script called __GenerateProjectFiles__:

- GenerateProjectFiles.bat
- GenerateProjectFiles.sh

Depending of the system (Unix bases or Window), run the proper script from the command line:

- If the plugin is inside the Project directory (Project/Plugins), go to the Project root directory and run the script.
- If the plugin is inside the Engine, run the command from the Unreal Engine source root directory.

Once the command have finished, type the _make_ command:

```bash
$ make
```

After a few seconds the plugin binary should be available.

#### Speed up plugin build phase

In some cases is required to re-build only the plugin, using a normak _make_ command can take some minutes as it does some parsing running some scripts to fix dependencies, to speed up the process the following options can be added:

```bash
$ make UE4Editor ARGS=-canskiplink
```

### Enable the Analytics plugins for your project

Inside the Unreal Engine 4 Editor, open your project and the _plugins_ window:

- Edit > Plugins

Now enable the two required plugins:

- Blueprints: located at Built-in > Analytics ![](http://edsiper.linuxchile.cl/ue4_blueprints_enable.jpg)
- Treasure Data: located at Installed > Analytics ![](http://edsiper.linuxchile.cl/ue4_td_plugin_enable.jpg)

### Configure Project settings

From your project directory, open and edit the file _Config/DefaultEngine.ini_ and append the following content at bottom:

```
[Analytics]
ProviderModuleName=TreasureData
TDApiKey=TD-WRITE-ONLY-KEY
TDDatabase=DATABASE_NAME
SendInterval=10

[AnalyticsDevelopment]
ProviderModuleName=TreasureData
TDApiKey=TD-WRITE-ONLY-KEY
TDDatabase=DATABASE_NAME
SendInterval=10

[AnalyticsTest]
ProviderModuleName=TreasureData
TDApiKey=TD-WRITE-ONLY-KEY
TDDatabase=DATABASE_NAME
SendInterval=10
```

Save the file and restart Unreal Engine Editor.
