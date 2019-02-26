<?php

require_once './libs/directoris.inc';
require_once './libs/arxius.inc';
require_once './libs/sistema.inc';
require_once './Constants.inc';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $command = $_POST["command"];
    $commandExplode = explode(" ", $command);

    if (strpos($command, "-") && substr($commandExplode[1], 0, 1) === '-') {
        $iterator = 0;
        $commandExplode[0] .= " " . $commandExplode[1];
        foreach ($commandExplode as $command) {
            if ($iterator > 1) {
                $commandExplode[$iterator - 1] = $command;
            }
            $iterator += 1;
        }
    }

    switch ($commandExplode[0]) {
        case COMMANDCREATEDIRECTORY:
            create_directory($commandExplode[1]);
            break;
        case COMMANDDELETEDIRECTORY:
            delete_directory($commandExplode[1]);
            break;
        case COMMANDMOVEDIRECTORY:
            move_directory($commandExplode[1], $commandExplode[2]);
            break;
        case COMMANDCOPYDIRECTORY:
            copy_directory($commandExplode[1], $commandExplode[2]);
            break;
        case COMMANDFINDFILE:
            find_file($commandExplode[1], $commandExplode[2]);
            break;
        case COMMANDSTATSFILE:
            stats_file($commandExplode[1]);
            break;
        case COMMANDDELETEFILE:
            delete_file($commandExplode[1]);
            break;
        case COMMANDMOVEFILE:
            move_file($commandExplode[1], $commandExplode[2]);
            break;
        case COMMANDCOPYFILE:
            copy_file($commandExplode[1], $commandExplode[2]);
            break;
        case COMMANDSHA1FILE:
            sha1_file_function($commandExplode[1]);
            break;
        case COMMANDMD5FILE:
            md5_file_function($commandExplode[1]);
            break;
        case COMMANDLSSYSTEM:
            llistat(getcwd());
            break;
        case COMMANDDIRSYSTEM:
            ruta();
            break;
        case COMMANDSTATSSYSTEMSYSTEM:
            stats_sistema(getcwd());
            break;
        case COMMANDHELP:
            commandExists();
            break;
        default:
            commandExists();
            break;
    }
}

function commandExists()
{
    foreach (help()['user'] as $command) {
        echo $command . "<br>";
    }
}
