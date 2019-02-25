<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    function create_directory($dir) {
        if (!mkdir($dir)) {
            return false;
        } else {
            return true;
        }
    }

    function delete_directory($dir) {
        //Comproba si la ruta introduïda es vàlida o no.
        if (is_dir($dir)) {
            //Si la ruta almacenada en el argumento $dir no tiene la barra al final se la agregamos
            if (substr($dir, strlen($dir) - 1, 1) != '') {
                $dir .= '\\';
            }

            //Obtenemos los elementos del directorio, ignorando el "." y ".."
            $elements = array_diff(scandir($dir), array('.', '..'));
            //Recorremos los elementos del directorio
            foreach ($elements as $element) {
                //Si es una carpeta
                if (is_dir($dir . $element)) {
                    delete_directory($dir . $element);
                } elseif (is_file($dir . $element)) {
                    unlink($dir . $element);
                }
            }

            //Una vez el directorio está vacío lo eliminamos
            if (rmdir($dir)) {
                echo "El directorio introducido y sus subdirectorios con sus respectivos archivos se han eliminado correctamente. <b>$dir</b><br/>";
            }
            //Quan el directori introduït no existeix ens informarà.
        } elseif (!is_dir($dir)) {
            echo "El directorio introducido <b>$dir</b> no es una ruta de directorio valida o bien no existe.<br/>";
        }
    }

    function move_directory($dir, $rutadesti) {
        $isMoved = false;
        if (is_dir($dir)) {
            $carpeta = scandir($dir);
            foreach ($carpeta as $file) {
                global $isMoved;
                if ($file != "." && $file != "..") {
                    if (!moveIfFileExist($dir, $rutadesti, $file, $isMoved)) {
                        $isMoved = copy($dir . "/" . $file, $rutadesti . "/" . $dir . "/" . $file);
                    }
                }
            }
        }
        $isMoved = rename($dir, $rutadesti . "/" . $dir);

        return $isMoved;
    }

    function copy_directory($dir, $rutadesti) {
        $explode = explode("/", $dir);
        return copy($dir, $rutadesti . "/" . $explode[1]);
    }

    function moveIfFileExist($dir, $rutadesti, $file, $isMoved) {
        echo $rutadesti;
        try {
            if (file_exists($dir . "/" . $rutadesti . "/" . $file)) {
                $fileExplode = explode('.', $file);
                $isMoved = copy($dir . "/" . $file, $rutadesti . "/" . $fileExplode[0] . "(Copia)." . $fileExplode[1]);
            }
        } catch (Exception $e) {
            echo 'Excepción capturada: ', $e->getMessage(), "\n";
        }
        return $isMoved;
    }

}
?>

