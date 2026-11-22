// func _apdb_ap_fwid_hash_free @ 005fa348 size=72

void _apdb_ap_fwid_hash_free(int param_1)

{
  if (param_1 != 0) {
    FUN_00408570(param_1,_apdb_fwid_node_free,0);
    FUN_00408310(param_1);
    return;
  }
  return;
}

