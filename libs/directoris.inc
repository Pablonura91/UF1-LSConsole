<?php
function create_directory($dir)
{
    if (!file_exists($dir)) {
        mkdir($dir);
        echo "$dir Creado correctamente";
    } else {
        echo "Error: $dir no se ha podido crear";
    }
}

function delete_directory($dir)
{
    //Comprueba si la ruta introduïda es valida o no.
    if (is_dir($dir)) {
        //Si la ruta almacenada en el argumento $dir no tiene la barra al final se la agregamos
        if (substr($dir, strlen($dir) - 1, 1) != '') {
            $dir .= '\\';
        }

        //Obtenemos los elementos del directorio, ignorando el "." y ".."
        $elements = array_diff(scandir($dir), array('.', '..'));
        //Recorremos los elementos del directorio
        foreach ($elements as $element) {
            if (is_dir($dir . $element)) {
                delete_directory($dir . $element);
            } elseif (is_file($dir . $element)) {
                unlink($dir . $element);
            }
        }

        //Una vez el directorio está vacío lo eliminamos
        if (rmdir($dir)) {
            echo "El directorio <b>$dir</b> introducido y sus subdirectorios con sus respectivos archivos se han eliminado correctamente.";
        }
        //Quando el directorio introducido no existe nos informara.
    } elseif (!is_dir($dir)) {
        echo "El directorio introducido <b>$dir</b> no es una ruta de directorio valida o bien no existe.";
    }
}

function move_directory($dir, $rutadesti)
{
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

    if ($isMoved) {
        echo "Directorio $dir se ha movido a $rutadesti correctamente";
    } else {
        echo "Ha ocurrido algun error y no se ha podido mover";
    }
}

function copy_directory($dir, $rutadesti)
{
    $explode = explode("/", $dir);
    if (copy($dir, $rutadesti . "/" . $explode[1])) {
        echo "Directorio $dir se ha copiado a $rutadesti correctamente";
    } else {
        echo "Ha ocurrido algun error y no se ha podido copiar";
    }
}

function moveIfFileExist($dir, $rutadesti, $file, $isMoved)
{
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

?>

