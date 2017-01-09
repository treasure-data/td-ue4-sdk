# Treasure Data Analytics Plugin for Unreal Engine 4

## Requirements

- Unreal Engine 4.14

## Getting Started

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

### Enable the Analytics plugins for your project

Inside the Unreal Engine 4 Editor, Open your project and open the _plugins_ window:

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
TDTable=TABLE_NAME
SendInterval=10

[AnalyticsDevelopment]
ProviderModuleName=TreasureData
TDApiKey=TD-WRITE-ONLY-KEY
TDDatabase=DATABASE_NAME
TDTable=TABLE_NAME
SendInterval=10

[AnalyticsTest]
ProviderModuleName=TreasureData
TDApiKey=TD-WRITE-ONLY-KEY
TDDatabase=DATABASE_NAME
TDTable=TABLE_NAME
SendInterval=10
```

Save the file and restart Unreal Engine Editor.
