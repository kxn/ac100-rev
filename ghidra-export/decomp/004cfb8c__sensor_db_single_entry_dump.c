// func _sensor_db_single_entry_dump @ 004cfb8c size=468

void _sensor_db_single_entry_dump(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int extraout_v1;
  char *pcVar6;
  int iVar7;
  
  if (param_1 != (ushort *)0x0) {
    if (*(char *)((int)param_1 + 3) == '\0') {
      pcVar6 = "Unfirm";
    }
    else {
      pcVar6 = "Firm";
    }
    uVar2 = (uint)*(byte *)((int)param_1 + 9);
    uVar3 = (uint)*(byte *)(param_1 + 5);
    uVar4 = (uint)*(byte *)(param_1 + 2);
    printf("%5u| %s|[%02x:%02x:%02x:%02x:%02x:%02x](%d)|\r\n",(uint)*param_1,pcVar6,
           (uint)*(byte *)((int)param_1 + 5),(uint)*(byte *)(param_1 + 3),
           (uint)*(byte *)((int)param_1 + 7),(uint)*(byte *)(param_1 + 4),uVar2,uVar3,uVar4);
    if (param_2 != 0) {
      FUN_00407e70();
      printf(" vap list(total:%d):\r\n",(int)(short)param_1[7]);
      for (iVar7 = 0; iVar7 < (short)param_1[7]; iVar7 = iVar7 + 1) {
        pbVar5 = (byte *)(*(int *)(param_1 + 10) + iVar7 * 0xc);
        printf("  [%02x:%02x:%02x:%02x:%02x:%02x]",(uint)*pbVar5,(uint)pbVar5[1],(uint)pbVar5[2],
               (uint)pbVar5[3],(uint)pbVar5[4],(uint)pbVar5[5],uVar2,uVar3,uVar4);
      }
      puts("\r");
      printf(" scan bssid list(total:%d):\r\n",(int)(short)param_1[6]);
      uVar1 = param_1[6];
      for (iVar7 = 0; iVar7 < (short)uVar1; iVar7 = iVar7 + 1) {
        pbVar5 = (byte *)(*(int *)(param_1 + 8) + iVar7 * 0x14);
        printf("  [%02x:%02x:%02x:%02x:%02x:%02x] | %d | %d | %d | %d | %d | %d |\r\n",(uint)*pbVar5
               ,(uint)pbVar5[1],(uint)pbVar5[2],(uint)pbVar5[3],(uint)pbVar5[4],(uint)pbVar5[5],
               (int)(char)pbVar5[6],(int)*(short *)(pbVar5 + 8),(int)(char)pbVar5[10],
               (int)(char)pbVar5[0xb],(int)(char)pbVar5[0xc],extraout_v1 - *(int *)(pbVar5 + 0x10));
        uVar1 = param_1[6];
      }
    }
  }
  return;
}

