// func _wsta_roam_db_print_sta_tmprcd_cb @ 00480b9c size=352

void _wsta_roam_db_print_sta_tmprcd_cb(byte *param_1)

{
  ushort *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  undefined *puVar5;
  byte *pbVar6;
  int iVar7;
  
  if (param_1 != (byte *)0x0) {
    printf("sta mac = [%02x:%02x:%02x:%02x:%02x:%02x]\n",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
    if (*(int *)(param_1 + 8) == 1) {
      puVar5 = &DAT_00693fd0;
    }
    else {
      puVar5 = &DAT_00693fd4;
    }
    iVar7 = 0;
    printf("old ft = %s\n",puVar5);
    printf("old rssi = %d\n",(int)(char)param_1[0xc]);
    __udivdi3(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,1000);
    printf("suggest time(sec) = %llu\n");
    printf("nbr_cnt = %u\n",(uint)param_1[0x38]);
    bVar4 = param_1[0x38];
    pbVar6 = param_1;
    while (iVar7 < (int)(uint)bVar4) {
      puVar1 = (ushort *)(pbVar6 + 0x18);
      pbVar2 = pbVar6 + 0x1a;
      iVar7 = iVar7 + 1;
      pbVar3 = pbVar6 + 0x1b;
      puVar5 = &DAT_00693fd0;
      if (*(int *)(pbVar6 + 0x1c) != 1) {
        puVar5 = &DAT_00693fd4;
      }
      pbVar6 = pbVar6 + 8;
      printf("\tap_id=%d, radio_id=%d, wlan_id=%d, ft=%s\n",(uint)*puVar1,(uint)*pbVar2,
             (uint)*pbVar3,puVar5);
      bVar4 = param_1[0x38];
    }
  }
  return;
}

