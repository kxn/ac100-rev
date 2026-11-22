// func _sensor_di_db_sensor_di_data_pkt_stat_free @ 004dc5bc size=388

void _sensor_di_db_sensor_di_data_pkt_stat_free(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    while (iVar1 = FUN_004081b0(param_1 + 0x1c530), iVar1 != 0) {
      while (iVar2 = FUN_004081b0(iVar1 + 0x48), iVar2 != 0) {
        while (iVar3 = FUN_004081b0(iVar2 + 0x2ac), iVar3 != 0) {
          FUN_00407f40(*(undefined4 *)(param_1 + 0x1c53c),iVar3);
          FUN_00408500(iVar3);
          FUN_00407df0(iVar3);
        }
        FUN_00407f40(*(undefined4 *)(param_1 + 0x1c540),iVar2);
        FUN_00408500(iVar2);
        FUN_00407df0(iVar2);
      }
      FUN_00407f40(*(undefined4 *)(param_1 + 0x1c544),iVar1);
      FUN_00408500(iVar1);
      FUN_00407df0(iVar1);
    }
    *(undefined2 *)(param_1 + 0x1c514) = 0;
    *(undefined4 *)(param_1 + 0x1c518) = 0;
    *(undefined4 *)(param_1 + 0x1c51c) = 0;
    *(undefined4 *)(param_1 + 0x1c520) = 0;
    memset((void *)(param_1 + 0x1c524),0,0xc);
    FUN_0051ad88(param_1 + 0x1c530);
    if (param_2 == 1) {
      FUN_00408310(*(undefined4 *)(param_1 + 0x1c53c));
      FUN_00408310(*(undefined4 *)(param_1 + 0x1c540));
      FUN_00408310(*(undefined4 *)(param_1 + 0x1c544));
      *(undefined4 *)(param_1 + 0x1c53c) = 0;
      *(undefined4 *)(param_1 + 0x1c540) = 0;
      *(undefined4 *)(param_1 + 0x1c544) = 0;
    }
  }
  return;
}

