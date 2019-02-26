<?php

//Funcio per buscar un arxiu en un directori en concret.
function find_file($source_route_file, $file)
{

    if (file_exists($source_route_file . "/" . $file)) {
        echo "El fichero <b>$file</b> si que existe en el direcotrio: <b>$source_route_file</b>";
    } else {
        echo "El fichero <b>$file</b> no existe en el directorio: <b>$source_route_file</b> ";
    }
}

//Funcion que nos mostrara los stats de un fichero
function stats_file($route_file_stats)
{
    //Captura la ruta y obtiene todas las estadisticas
    $statistics = stat($route_file_stats);

    if ($statistics) {
        $statistics_file_name = explode(".", $route_file_stats);
        $statistics_file_name2 = $statistics_file_name[0];
        $statistics_access_file = date("d F Y H:i:s", $statistics['atime']);
        $statistics_modification_file = date("d F Y H:i:s", $statistics['mtime']);
        $statistics_creation_file = date("d F Y H:i:s", $statistics['ctime']);
        $statistics_size_file = $statistics['size'];

        echo "<table class='table table-bordered'> 
                <thead>
                    <tr>	
                        <th>Ruta Completa</th>
                        <th>Nom</th>
                        <th>Tamany</th> 
                        <th>Creació</th> 
                        <th>Modificació</th> 
                        <th>Últim accès</th>	 
                    </tr>
                </thead>
                <tbody>
                    <tr>            
                        <th>$route_file_stats</th>
                        <th>$statistics_file_name2</th>
                        <th>$statistics_size_file bytes</th>
                        <th>$statistics_creation_file</th>
                        <th>$statistics_modification_file</th>	
                        <th>$statistics_access_file</th>
                    </tr>
                </tbody>
              </table>";
    }
}

//Funcion que nos eliminara el fichero de un directorio concreto
function delete_file($delete_file)
{
    $deletefile = unlink($delete_file);

    if ($deletefile) {
        echo "El fichero: <b>$delete_file</b> ha sido eliminado correctamente.";
    }
}

//Funcion que nos movera un archivo a otro
function move_file($source_route, $destination_route)
{
    $movefile = rename($source_route, $destination_route);

    if ($movefile) {
        echo "El fichero $source_route se ha movido correctamente a $destination_route.";
    }
}

//Funcion que nos copiara un arxivo a otro directorio
function copy_file($source_route, $destination_route)
{
    $copyfile = copy($source_route, $destination_route);

    if ($copyfile) {
        echo "Se ha copiado correctamente.";
    }
}

//Funcion que nos retornara el hash sha1 de un fichero
function sha1_file_function($dir)
{
    $sha1file = sha1_file($dir);

    if ($sha1file) {
        echo "El hash <b>sha1</b> del fitxer: <b>$dir</b> es: <b>$sha1file</b>";
    }
}

//Funcion que nos retornara el hash md5 de un fichero
function md5_file_function($dir)
{
    $md5file = md5_file($dir);

    if ($md5file) {
        echo "El hash <b>md5</b> del fitxer contingut en el directori: <b>$dir</b> es: <b>$$md5file</b>";
    }
}

