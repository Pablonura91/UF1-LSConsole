<?php
function list_file($ruta) {
    if (is_dir($ruta)) {
        //Abre un gestor de directorios de la ruta especificada
        $gestor = opendir($ruta);
        echo "<ul>";

        //Recorre todos los elementos del directorio
        while ($archivo = readdir($gestor)) {

            $ruta_completa = $ruta . "\\" . $archivo;

            if ($archivo != "." && $archivo != "..") {
                if (is_dir($ruta_completa)) {
                    echo "<li> $archivo </li>";
                    list_file($ruta_completa);
                }
                elseif (is_file($ruta_completa)) {
                    echo "<li> $archivo </li>";
                }
            }
        }

        closedir($gestor);
        echo "</ul>";

    } elseif (!is_dir($ruta)) {
        echo "El directorio base: <b>$ruta</b> no es una ruta de directorio válida o bien no existe.<br/>";
    }
}

//Funcion que devuelve la ruta actual del directorio
function ruta() {
    echo getcwd();
}

//Funcion que devuelve los stats de la unidad escogida
function stats_system($dir) {
    //Separo la ruta y extraemos la letra de la unidad
    $currentPartitionExplode = explode(":", $dir);
    $currentPartition = $currentPartitionExplode[0];

    if (is_dir($dir)) {

        //Espacio total de la unidad.
        $disk_total_space = disk_total_space("$currentPartition:");

        //Espacio libre de la unidad.
        $disk_free_space = disk_free_space("$currentPartition:");

        //Espacio utilizado de la unidad.
        $disk_used_space = $disk_total_space - $disk_free_space;

        //Conversion de diferente formatos del espacio total de la unidad
        $disk_total_space_convertedKB = round(($disk_total_space / 1024), $presicion = 2);
        $disk_total_space_convertedMB = round(($disk_total_space_convertedKB / 1024), $presicion = 2);
        $disk_total_space_convertedGB = round(($disk_total_space_convertedMB / 1024), $presicion = 2);
        $disk_total_space_convertedTB = round(($disk_total_space_convertedGB / 1024), $presicion = 2);

        //Conversion en diferentes formatos del espacio libre de la unidad
        $disk_free_space_convertedKB = round(($disk_free_space / 1024), $presicion = 2);
        $disk_free_space_convertedMB = round(($disk_free_space_convertedKB / 1024), $presicion = 2);
        $disk_free_space_convertedGB = round(($disk_free_space_convertedMB / 1024), $presicion = 2);
        $disk_free_space_convertedTB = round(($disk_free_space_convertedGB / 1024), $presicion = 3);

        //Conversion ed diferentes formatos del espacio utilizado de la unidad
        $disk_used_space_convertedKB = round(($disk_used_space / 1024), $presicion = 2);
        $disk_used_space_convertedMB = round(($disk_used_space_convertedKB / 1024), $presicion = 2);
        $disk_used_space_convertedGB = round(($disk_used_space_convertedMB / 1024), $presicion = 2);
        $disk_used_space_convertedTB = round(($disk_used_space_convertedGB / 1024), $presicion = 3);

        //Conversion en procentaje del espacio libre y utilizado de la unidad
        $disk_used_space_percent = round(($disk_used_space / $disk_total_space) * 100);
        $disk_free_space_percent = round(($disk_free_space / $disk_total_space) * 100);

        echo "La unidad / particion analizada es la: <b>$currentPartition</b>";
        echo "Espacio usado ($disk_used_space_percent %): $disk_used_space bytes. #### $disk_used_space_convertedKB KB. #### $disk_used_space_convertedMB MB. #### $disk_used_space_convertedGB GB. #### $disk_used_space_convertedTB TB.";
        echo "Espacio disponible ($disk_free_space_percent %): $disk_free_space bytes. #### $disk_free_space_convertedKB KB. #### $disk_free_space_convertedMB MB. #### $disk_free_space_convertedGB GB. #### $disk_free_space_convertedTB TB.";
        echo "Capacidad total: $disk_total_space bytes. #### $disk_total_space_convertedKB KB. #### $disk_total_space_convertedMB MB. #### $disk_total_space_convertedGB GB. #### $disk_total_space_convertedTB TB.";
    } //Comprobo que la ruta introduïda no té una lletra d'unitat/partició vàlides.
    elseif (!is_dir($dir)) {
        echo "La letra de unidad: <b>$currentPartition</b> introducida no existe o bien no esta disponible en este momento.";
    }
}

