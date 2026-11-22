// func _sensor_di_ssidinfo_node_free @ 004d1e38 size=148

void _sensor_di_ssidinfo_node_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1 + 0xc), iVar1 != 0) {
      FUN_00408500(iVar1);
      if (*(int *)(iVar1 + 0x24) != 0) {
        FUN_00407df0();
        *(undefined4 *)(iVar1 + 0x24) = 0;
      }
      FUN_00407df0(iVar1);
    }
    FUN_00407df0(param_1);
    return;
  }
  return;
}

