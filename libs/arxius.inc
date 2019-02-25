<?php

//Funcio per buscar un arxiu en un directori en concret.
function find_file($source_route_file, $file) {

    if (file_exists($source_route_file . "/" . $file)) {
        echo "El fichero " . "<b>$file</b>" . " si que existe en el direcotrio: " . "<b>$source_route_file</b>";
    }
}

//Funció que ens mostrarà una sèrie d'informació/estadístiques d'un fitxer en concret.
function stats_file($route_file_stats) {
    //Captura la ruta + nom_fitxer, i obte totes les estadístiques del fitxer introduït.
    $statistics = stat($route_file_stats);

    //Si l'arxiu existeix, s'agafen correctament les estadístiques.
    if ($statistics) {
        //Agafo les estadístiques més rellevants del fitxer.
        $statistics_file_name = explode(".", $route_file_stats);
        $statistics_file_name2 = $statistics_file_name[0];
        $statistics_access_file = date("d F Y H:i:s", $statistics['atime']);
        $statistics_modification_file = date("d F Y H:i:s", $statistics['mtime']);
        $statistics_creation_file = date("d F Y H:i:s", $statistics['ctime']);
        $statistics_size_file = $statistics['size'];

        //Imprimeixo les estadístiques solicitades.
        echo " <table border='1'>
                            <tr>	
                                <th bgcolor='#FFFFFFFF'>Ruta Completa</th>
                                <th bgcolor='#FFFFFFFF'>Nom</th>
                                <th bgcolor='#FFFFFFFF'>Tamany</th> 
                                <th bgcolor='#FFFFFFFF'>Creació</th> 
                                <th bgcolor='#FFFFFFFF'>Modificació</th> 
                                <th bgcolor='#FFFFFFFF'>Últim accès</th>	 
                            </tr>
                            
                            <td>$route_file_stats</td>
                            <td>$statistics_file_name2</td>
                            <td>$statistics_size_file bytes</td>
                            <td>$statistics_creation_file</td>
                            <td>$statistics_modification_file</td>	
                            <td>$statistics_access_file</td>
                        </table>";

        echo "<br></br>";
    }
}

//Funció que ens eliminarà un fitxer d'un directori concret.
function delete_file($delete_file) {
    //Eliminem el fitxer
    $deletefile = unlink($delete_file);

    //si el fitxer s'ha eliminar correctament, ens n'informarà.
    if ($deletefile) {
        echo "El fichero: " . "<b>$delete_file</b>" . " ha sido eliminado correctamente.";
    }
}

//Funció que ens mourà l'arxiu d'un directori cap a un altre.
function move_file($source_route, $destination_route) {
    //Movem l'arxiu del directori origen al directori destí (podem renombrar el nom d'arxiu o possar-li el mateix).
    $movefile = rename($source_route, $destination_route);

    //Si l'arxiu s'ha mogut correctament, ens informarà que s'ha mogut.
    if ($movefile) {
        echo "Se ha movido correctamente.";
    }
}

//Funció que ens copiara un arxiu d'un direcotri cap a un altre.
function copy_file($source_route, $destination_route) {
    //Copiem l'arxiu del directori origen al directori destí (podem renombrar el nom d'arxiu o possar-li el mateix).
    $copyfile = copy($source_route, $destination_route);

    //Si l'arxiu s'ha copiat correctament, ens informarà que s'ha copiat.
    if ($copyfile) {
        echo "Se ha copiado correctamente.";
    }
}

//Funció que ens retorna el hash sha1 d’un fitxer.
function sha1_file_function($dir) {
    //Obtinc el hash sha1 de l'arxiu.
    $sha1file = sha1_file($dir);

    //Si s'ha obtingut el hash correctament, ens el mostrarà.
    if ($sha1file) {
        echo "El hash " . "<b>sha1</b>" . " del fitxer: " . "<b>$dir</b>" . " es: " . "<b>$sha1file</b>";
    }
}

//Funció que ens retorna el hash md5 d’un fitxer.
function md5_file_function($dir) {
    //Obtinc el hash md5 de l'arxiu.
    $md5file = md5_file($dir);

    //Si s'ha obtingut el hash correctament, ens el mostrarà.
    if ($md5file) {
        echo "El hash " . "<b>md5</b>" . " del fitxer contingut en el directori: " . "<b>$dir</b>" . " es: " . "<b>$$md5file</b>";
    }
}

