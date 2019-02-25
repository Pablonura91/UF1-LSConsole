<?php

require_once './libs/directoris.inc';
require_once './libs/arxius.inc';
require_once './libs/sistema.inc';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $command = $_POST["command"];
    $commandExplode = explode(" ", $command);
    
    if (substr($commandExplode[1], 0, 1) === '-') {
        $iterator = 0;
        $commandExplode[0] .= " ". $commandExplode[1];
        foreach ($commandExplode as $command) {
            if ($iterator > 1) {
                $commandExplode[$iterator - 1] = $command;
            }
            $iterator += 1;
        }
    }

    switch ($commandExplode[0]) {
        case "mkdir":
            if (create_directory($commandExplode[1])) {
                echo "Creat correctament";
            } else {
                echo "Hi ha agut un error";
            }
            break;
        case "rm -d":
            delete_directory($commandExplode[1]);
            break;
        case "mv -d":
            move_directory($commandExplode[1], $commandExplode[2]);
            break;
        case "cp -d":
            copy_directory($commandExplode[1], $commandExplode[2]);
            break;
        case "find":
            find_file($commandExplode[1], $commandExplode[2]);
            break;
        case "stats":
            stats_file($commandExplode[1]);
            break;
        case "rm -f":
            delete_file($commandExplode[1]);
            break;
        case "mv -f":
            move_file($commandExplode[1], $commandExplode[2]);
            break;
        case "cp -f":
            copy_file($commandExplode[1], $commandExplode[2]);
            break;
        case "sha1":
            sha1_file_function($commandExplode[1]);
            break;
        case "md5":
            md5_file_function($commandExplode[1]);
            break;
        default:
            break;
    }
}

function commandExists() {
    return "mkdir directori</br> rm -d directori</br> mv -d  directori desti</br> cp -d directori desti </br>";
}
