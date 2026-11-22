// func _audit_client_sc_free_cb @ 00508b74 size=24

void _audit_client_sc_free_cb(int param_1)

{
  if (param_1 != 0) {
    audit_client_db_msg_free();
    return;
  }
  return;
}

