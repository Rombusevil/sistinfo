<?php

// Devuelve el nextid y lo aumenta en 1
function incrementSequence($tabla) {
    $db = &atkGetDb();

    $result = $db->getrows("SELECT nextid from db_sequence where seq_name = '$tabla';");

    if ($result == NULL) {
        $db->query("INSERT INTO db_sequence (seq_name, nextid) VALUES ('$tabla', 2);");
        $newId = 1;
    } else {
        $newId = $result[0]["nextid"] + 1;
        $db->query("UPDATE db_sequence set nextid =$newId where seq_name = '$tabla';");
    }

    return $newId;
}
