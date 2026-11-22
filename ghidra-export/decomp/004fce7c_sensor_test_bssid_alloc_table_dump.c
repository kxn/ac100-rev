// func sensor_test_bssid_alloc_table_dump @ 004fce7c size=1

void sensor_test_bssid_alloc_table_dump(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  puts("=========bssid alloc table============");
  for (uVar4 = 0; uVar1 = sensor_test_db_get_case_num_max(), uVar4 < uVar1; uVar4 = uVar4 + 1) {
    iVar5 = uVar4 * 4;
    if (*(undefined4 **)(l_sensor_test_ssid_alloc_list + iVar5) != (undefined4 *)0x0) {
      printf("case_id=%d\n",**(undefined4 **)(l_sensor_test_ssid_alloc_list + iVar5));
      printf("ssid_cnt=%d\n",*(undefined4 *)(*(int *)(l_sensor_test_ssid_alloc_list + iVar5) + 4));
      puts("bssid_alloc_list:");
      for (iVar3 = 0; iVar3 < *(int *)(*(int *)(l_sensor_test_ssid_alloc_list + iVar5) + 4);
          iVar3 = iVar3 + 1) {
        for (iVar2 = FUN_004081b0(*(int *)(*(int *)(l_sensor_test_ssid_alloc_list + iVar5) + 8) +
                                  iVar3 * 0x14 + 8); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
          printf("   BSSID is=%.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",(uint)*(byte *)(iVar2 + 0xc),
                 (uint)*(byte *)(iVar2 + 0xd),(uint)*(byte *)(iVar2 + 0xe),
                 (uint)*(byte *)(iVar2 + 0xf),(uint)*(byte *)(iVar2 + 0x10),
                 (uint)*(byte *)(iVar2 + 0x11));
          printf("   case_id=%d, serv_id=%d, freqband=%d\n",*(undefined4 *)(iVar2 + 0x18),
                 *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x1c));
          printf("   status=%d, sensor_id=%d, rssi=%d\n",(uint)*(byte *)(iVar2 + 0x22),
                 (uint)*(ushort *)(iVar2 + 0x20),(int)*(char *)(iVar2 + 0x23));
          puts("\n");
        }
      }
      puts("///////////////////");
    }
  }
  (*(code *)PTR_puts_00758f90)("======================================");
  return;
}

