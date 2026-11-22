// func apupd_transfer_softver_str_to_softver_struct @ 006571cc size=944

undefined4 apupd_transfer_softver_str_to_softver_struct(char *param_1,undefined2 *param_2)

{
  size_t __n;
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78 [6];
  char acStack_60 [68];
  
  if ((param_1 == (char *)0x0) || (param_2 == (undefined2 *)0x0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APUPD_ERROR]%32s() %05d: Input Argument Error!\r\n";
    uVar5 = 0x220e;
LAB_00657320:
    printf(pcVar2,"apupd_transfer_softver_str_to_softver_struct",uVar5);
    return 0xffffffff;
  }
  memset(acStack_60,0,0x40);
  __n = strlen(param_1);
  if (0x3f < __n) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APUPD_ERROR]%32s() %05d: Soft version string is too long!\r\n";
    uVar5 = 0x2216;
    goto LAB_00657320;
  }
  memcpy(acStack_60,param_1,__n);
  puVar1 = (undefined4 *)FUN_00408450(0x14,0x221d);
  if (puVar1 == (undefined4 *)0x0) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar7 = is_target_debug_ap();
    if (iVar7 == 0) {
      return 0xffffffff;
    }
    pcVar2 = "[APUPD_ERROR]%32s() %05d: Malloc fail!\r\n";
    uVar5 = 0x2220;
    goto LAB_00657320;
  }
  pcVar2 = strtok(acStack_60," ");
  puVar8 = puVar1;
  for (iVar7 = 0; (pcVar2 != (char *)0x0 && (iVar7 != 4)); iVar7 = iVar7 + 1) {
    *puVar8 = pcVar2;
    pcVar2 = strtok((char *)0x0," ");
    puVar8 = puVar8 + 1;
  }
  puVar1[iVar7] = 0;
  iVar7 = sscanf((char *)*puVar1,"%d.%d.%d",&local_7c,&local_80,&local_84);
  if (iVar7 == 3) {
    local_78[0] = 0;
    local_78[1] = 0;
    *param_2 = (short)local_7c;
    local_78[2] = 0;
    local_78[3] = 0;
    param_2[1] = (short)local_80;
    local_78[4] = 0;
    local_78[5] = 0;
    param_2[2] = (short)local_84;
    memcpy(local_78,(void *)puVar1[2],4);
    iVar7 = atoi((char *)local_78);
    local_78[1] = 0;
    *(int *)(param_2 + 4) = iVar7 << 0x10;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[0] = (uint)*(ushort *)(puVar1[2] + 4) << 0x10;
    iVar3 = atoi((char *)local_78);
    local_78[1] = 0;
    uVar6 = iVar3 << 8 | iVar7 << 0x10;
    local_78[2] = 0;
    *(uint *)(param_2 + 4) = uVar6;
    local_78[3] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[0] = (uint)*(ushort *)(puVar1[2] + 6) << 0x10;
    uVar4 = atoi((char *)local_78);
    *(uint *)(param_2 + 4) = uVar6 | uVar4;
    iVar7 = sscanf((char *)puVar1[3],"Rel.%d",&local_88);
    if (iVar7 == 1) {
      *(undefined4 *)(param_2 + 6) = local_88;
      FUN_00407df0(puVar1);
      if (g_apupd_debug == 0) {
        return 0;
      }
      iVar7 = is_target_debug_ap();
      if (iVar7 != 0) {
        printf("[APUPD_DEBUG]%32s() %05d: %d.%d.%d %d %d\r\n",
               "apupd_transfer_softver_str_to_softver_struct",0x224f,local_7c,local_80,local_84,
               *(undefined4 *)(param_2 + 4),local_88);
        return 0;
      }
      return 0;
    }
    if ((g_apupd_error == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0)) goto LAB_0065750c;
    pcVar2 = "[APUPD_ERROR]%32s() %05d: Get soft version params(build time) fail!\r\n";
    uVar5 = 0x2245;
  }
  else {
    if ((g_apupd_error == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0)) goto LAB_0065750c;
    pcVar2 = "[APUPD_ERROR]%32s() %05d: Get soft version params(major, minor, ver_rev) fail!\r\n";
    uVar5 = 0x222f;
  }
  printf(pcVar2,"apupd_transfer_softver_str_to_softver_struct",uVar5);
LAB_0065750c:
  FUN_00407df0(puVar1);
  return 0xffffffff;
}

