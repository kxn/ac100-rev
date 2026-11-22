// func _sensor_di_ssidinfo_list_free @ 004d1ecc size=84

void _sensor_di_ssidinfo_list_free(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1), iVar1 != 0) {
      FUN_00408500(iVar1);
      _sensor_di_ssidinfo_node_free(iVar1);
    }
  }
  return;
}

