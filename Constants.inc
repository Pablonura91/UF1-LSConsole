<?php
define("COMMANDCREATEDIRECTORY", "mkdir");
define("COMMANDDELETEDIRECTORY", "rm -d");
define("COMMANDMOVEDIRECTORY", "mv -d");
define("COMMANDCOPYDIRECTORY", "cp -d");
define("COMMANDFINDFILE", "find");
define("COMMANDSTATSFILE", "stats");
define("COMMANDDELETEFILE", "rm -f");
define("COMMANDMOVEFILE", "mv -f");
define("COMMANDCOPYFILE", "cp -f");
define("COMMANDSHA1FILE", "sha1");
define("COMMANDMD5FILE", "md5");
define("COMMANDLSSYSTEM", "ls");
define("COMMANDDIRSYSTEM", "pwd");
define("COMMANDSTATSSYSTEMSYSTEM", "systeminfo");
define("COMMANDHELP", "help");

function help()
{
    return get_defined_constants(TRUE);
}

?>
