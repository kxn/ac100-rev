// func di_pkt_stat_dump @ 004e1f5c size=1

void di_pkt_stat_dump(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _sensor_di_db_get_sensor_node_from_cached_list();
  if (iVar1 == 0) {
    printf("sensor_id=%d\'s data not found\n",param_1);
    return;
  }
  printf("sensor_id=%d:\n",param_1);
  printf("total_airtime=%d\n",*(undefined4 *)(iVar1 + 0x1c518));
  printf("total_pkt_num=%d\n",*(undefined4 *)(iVar1 + 0x1c51c));
  uVar2 = FUN_00407ed0(*(undefined4 *)(iVar1 + 0x1c53c));
  printf("ssid_hash_size=%d\n",uVar2);
  uVar2 = FUN_00407ed0(*(undefined4 *)(iVar1 + 0x1c540));
  printf("bssid_hash_size=%d\n",uVar2);
  uVar2 = FUN_00407ed0(*(undefined4 *)(iVar1 + 0x1c544));
  printf("sssid_hash_size=%d\n",uVar2);
  for (iVar1 = FUN_004081b0(iVar1 + 0x1c530); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    if (param_2 != 0) {
      printf("ssid name = %s,   id=%d,  pkt_num=%d,  air_time=%d\n",iVar1 + 0xc,
             (int)*(short *)(iVar1 + 0x3e),*(undefined4 *)(iVar1 + 0x44),
             *(undefined4 *)(iVar1 + 0x40));
    }
    for (iVar3 = FUN_004081b0(iVar1 + 0x48); iVar3 != 0; iVar3 = FUN_00408680(iVar3)) {
      if (param_3 != 0) {
        printf("====");
        di_printmac(iVar3 + 0xc);
        printf("====bssid\'s pkt_num=%d, air_time=%d\n",*(undefined4 *)(iVar3 + 0x18),
               *(undefined4 *)(iVar3 + 0x14));
      }
      for (iVar4 = FUN_004081b0(iVar3 + 0x2ac); iVar4 != 0; iVar4 = FUN_00408680(iVar4)) {
        if (param_4 != 0) {
          printf("========");
          di_printmac(iVar4 + 0xc);
          printf("========sta\'s pkt_num=%d, air_time=%d\n",*(undefined4 *)(iVar4 + 0x18),
                 *(undefined4 *)(iVar4 + 0x14));
        }
      }
    }
  }
  return;
}

