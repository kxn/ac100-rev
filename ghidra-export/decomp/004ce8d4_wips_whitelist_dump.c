// func wips_whitelist_dump @ 004ce8d4 size=444

void wips_whitelist_dump(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined2 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30;
  
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  FUN_004082d0(wips_global_mutex,0xffffffff);
  iVar2 = FUN_004081b0(&g_white_list);
  if (iVar2 != 0) {
    uVar4 = *(undefined4 *)(iVar2 + 0x58);
    while( true ) {
      wips_time2str(uVar4,&local_48);
      wips_time2str(*(undefined4 *)(iVar2 + 0x54),&local_64);
      printf("[%d]: ",*(undefined4 *)(iVar2 + 0xc));
      iVar3 = memcmp((void *)(iVar2 + 0x10),&DAT_006a81e4,6);
      if (iVar3 == 0) {
        cVar1 = *(char *)(iVar2 + 0x16);
      }
      else {
        wips_mac2str((void *)(iVar2 + 0x10),&local_78);
        printf("mac: %s, ",&local_78);
        cVar1 = *(char *)(iVar2 + 0x16);
      }
      if (cVar1 == '\0') {
        uVar5 = (uint)*(ushort *)(iVar2 + 0x4c);
      }
      else if (*(int *)(iVar2 + 0x48) == 0) {
        uVar5 = (uint)*(ushort *)(iVar2 + 0x4c);
      }
      else {
        printf("ssid: %s[%d], ",iVar2 + 0x16);
        uVar5 = (uint)*(ushort *)(iVar2 + 0x4c);
      }
      if (uVar5 != 0xffff) {
        printf("sensor_id: %d, rssi: %d, last_discover_time: %s, ",uVar5,
               *(undefined4 *)(iVar2 + 0x50),&local_64);
      }
      printf("ope_time: %s\n",&local_48);
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      uVar4 = *(undefined4 *)(iVar2 + 0x58);
    }
  }
  FUN_00407f30(wips_global_mutex);
  return;
}

