// func audit_client_db_msg_free @ 0050a18c size=88

void audit_client_db_msg_free(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if ((*(int *)(param_1 + 0x10) != 0) && (*(code **)(param_1 + 0x14) != (code *)0x0)) {
    (**(code **)(param_1 + 0x14))();
  }
  FUN_00407df0(param_1);
  return;
}

