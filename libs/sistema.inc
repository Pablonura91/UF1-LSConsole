<?php
function llistat($ruta) {
    //Confirmació que realment es la ruta d'un directori i que aquesta existeix.
    if (is_dir($ruta)) {
        //Obre un gestor de directoris per a la ruta indicada.
        $gestor = opendir($ruta);
        echo "<ul>";

        //Recorre tots els elements del directori de forma recursiva.
        while ($archivo = readdir($gestor)) {

            //Ruta complerta: directori + arxiu
            $ruta_completa = $ruta . "\\" . $archivo;

            //Es mostren tots els arxius i carpetes excepte els directoris predeterminat i funcionals del sistema ocults "." i ".."
            if ($archivo != "." && $archivo != "..") {
                //Si es un directori, aquest es recorreà recursivament fins haber recorregut tots els sub-directoris.
                //S'imprimeixen tots els directoris continguts en el direcotri base i es torna a cridar a la funció.
                if (is_dir($ruta_completa)) {
                    echo "<li>" . $archivo . "</li>";
                    llistat($ruta_completa);
                } //S'imprimeixen tots els fitxers continguts en el direcotri base.
                elseif (is_file($ruta_completa)) {
                    echo "<li>" . $archivo . "</li>";
                }
            }
        }
        //Tanquem el gestor de directoris, per evitar que gasti recursos de forma inecessària del O.S.
        closedir($gestor);
        echo "</ul>";
        //Confirmació que la ruta introduïda no existeix o be que no te el format correcte.
    } elseif (!is_dir($ruta)) {
        echo "El directorio base: <b>$ruta</b> no es una ruta de directorio válida o bien no existe.<br/>";
    }
}

//Funció que retorna la ruta actual del directori on es troba en execució la consola.
function ruta() {
    echo getcwd();
}

//Funció que retorna la mida total, l'espai ocupat i l'espai lliure de la unitat escollida per analitzar.
function stats_sistema($dir) {
    //Capturo la ruta introduïda
    $current_partition_letter = $dir;

    //Separo la ruta i extrec la lletra de la unitat/partició a analitzar.
    $current_partition_letter2 = explode(":", $current_partition_letter);
    $current_partition_letter3 = $current_partition_letter2[0];

    //Comprobo que la ruta introduïda té una lletra d'unitat/partició vàlides.
    if (is_dir($current_partition_letter)) {

        //Espai total de la unitat.
        $disk_total_space = disk_total_space("$current_partition_letter3:");

        //Espai lliure de la unitat.
        $disk_free_space = disk_free_space("$current_partition_letter3:");

        //Espai utilitzat de la unitat.
        $disk_used_space = $disk_total_space - $disk_free_space;

        //Conversió en diferents formats de l'espai total de l'unitat.
        $disk_total_space_convertedKB = round(($disk_total_space / 1024), $presicion = 2);
        $disk_total_space_convertedMB = round(($disk_total_space_convertedKB / 1024), $presicion = 2);
        $disk_total_space_convertedGB = round(($disk_total_space_convertedMB / 1024), $presicion = 2);
        $disk_total_space_convertedTB = round(($disk_total_space_convertedGB / 1024), $presicion = 2);

        //Conversió en diferents formats de l'espai lliure de l'unitat.
        $disk_free_space_convertedKB = round(($disk_free_space / 1024), $presicion = 2);
        $disk_free_space_convertedMB = round(($disk_free_space_convertedKB / 1024), $presicion = 2);
        $disk_free_space_convertedGB = round(($disk_free_space_convertedMB / 1024), $presicion = 2);
        $disk_free_space_convertedTB = round(($disk_free_space_convertedGB / 1024), $presicion = 3);

        //Conversió en diferents formats de l'espai utilitzat de l'unitat.
        $disk_used_space_convertedKB = round(($disk_used_space / 1024), $presicion = 2);
        $disk_used_space_convertedMB = round(($disk_used_space_convertedKB / 1024), $presicion = 2);
        $disk_used_space_convertedGB = round(($disk_used_space_convertedMB / 1024), $presicion = 2);
        $disk_used_space_convertedTB = round(($disk_used_space_convertedGB / 1024), $presicion = 3);

        //Conversió en percentatge de l'espai lliure i utilitzat de l'unitat.
        $disk_used_space_percent = round(($disk_used_space / $disk_total_space) * 100);
        $disk_free_space_percent = round(($disk_free_space / $disk_total_space) * 100);

        //Imprimeixo la informació demanada.
        echo "La unidad / particion analizada es la: <b>$current_partition_letter3</b>";
        echo "<br></br>";

        echo "Espacio usado ($disk_used_space_percent %): " . $disk_used_space . " bytes. #### " . $disk_used_space_convertedKB . " KB. #### " . $disk_used_space_convertedMB . " MB. #### " . $disk_used_space_convertedGB . " GB. #### " . $disk_used_space_convertedTB . " TB.";
        echo "<br></br>";

        echo "Espacio disponible ($disk_free_space_percent %): " . $disk_free_space . " bytes. #### " . $disk_free_space_convertedKB . " KB. #### " . $disk_free_space_convertedMB . " MB. #### " . $disk_free_space_convertedGB . " GB. #### " . $disk_free_space_convertedTB . " TB.";
        echo "<br></br>";

        echo "Capacidad total: " . $disk_total_space . " bytes. #### " . $disk_total_space_convertedKB . " KB. #### " . $disk_total_space_convertedMB . " MB. #### " . $disk_total_space_convertedGB . " GB. #### " . $disk_total_space_convertedTB . " TB.";
    } //Comprobo que la ruta introduïda no té una lletra d'unitat/partició vàlides.
    elseif (!is_dir($dir)) {
        echo "La letra de unidad: <b>$current_partition_letter3</b> introducida no existe o bien no esta disponible en este momento.";
    }
}

