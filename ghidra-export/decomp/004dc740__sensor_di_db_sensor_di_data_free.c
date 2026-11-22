// func _sensor_di_db_sensor_di_data_free @ 004dc740 size=344

void _sensor_di_db_sensor_di_data_free(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : _sensor_di_db_sensor_di_data_free ENTER\n",
           "_sensor_di_db_sensor_di_data_free",0x149);
  }
  if (param_1 == 0) {
    return;
  }
  iVar1 = FUN_00407fe0(param_1 + 0x18);
  if (iVar1 != 0) {
    iVar1 = FUN_004081b0(param_1 + 0x18,1);
    while (iVar1 != 0) {
      iVar2 = FUN_00408680(iVar1,1);
      iVar3 = FUN_00407fe0(iVar1 + 0xc);
      if (iVar3 != 0) {
        iVar3 = FUN_004081b0(iVar1 + 0xc);
        while (iVar3 != 0) {
          iVar4 = FUN_00408680(iVar3);
          if (*(int *)(iVar3 + 0x24) != 0) {
            FUN_00407df0();
            *(undefined4 *)(iVar3 + 0x24) = 0;
            *(undefined2 *)(iVar3 + 0x1a) = 0;
          }
          FUN_00408500(iVar3);
          FUN_00407df0(iVar3);
          iVar3 = iVar4;
        }
      }
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
      iVar1 = iVar2;
    }
  }
  _sensor_di_db_sensor_di_data_pkt_stat_free(param_1);
  FUN_00407df0(param_1);
  return;
}

