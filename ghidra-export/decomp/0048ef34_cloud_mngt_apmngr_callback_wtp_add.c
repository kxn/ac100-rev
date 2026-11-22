// func cloud_mngt_apmngr_callback_wtp_add @ 0048ef34 size=816

undefined4 cloud_mngt_apmngr_callback_wtp_add(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *__s;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  void *__s_00;
  char *__src;
  undefined4 extraout_v1;
  undefined1 auStack_188 [128];
  undefined4 local_108;
  char acStack_f0 [66];
  char acStack_ae [65];
  char local_6d [81];
  
  memset(auStack_188,0,0x168);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_add start\n",
           "cloud_mngt_apmngr_callback_wtp_add",0xd7e);
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  iVar1 = _cloud_mngt_role_match(*(undefined4 *)(param_1 + 0x14));
  if (iVar1 == 0) {
    return 0;
  }
  if (ap_report_switch == 0) {
    return 0;
  }
  puVar2 = (undefined4 *)FUN_00408450(0x14,0xd88);
  if (puVar2 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  puVar2[3] = 1;
  __s = (undefined4 *)FUN_00408450(0x20,0xd8e);
  if (__s == (undefined4 *)0x0) {
LAB_0048f254:
    FUN_00407df0(puVar2);
    return 0xffffffff;
  }
  memset(__s,0,0x20);
  uVar3 = (uint)*(byte *)(param_1 + 0x4a);
  uVar4 = (uint)*(byte *)(param_1 + 0x4b);
  uVar5 = (uint)*(byte *)(param_1 + 0x4c);
  uVar6 = (uint)*(byte *)(param_1 + 0x4d);
  snprintf((char *)(__s + 1),0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x48),
           (uint)*(byte *)(param_1 + 0x49),uVar3,uVar4,uVar5,uVar6);
  memcpy((void *)((int)__s + 0x16),(void *)(param_1 + 0x48),6);
  *__s = 1;
  __s_00 = (void *)FUN_00408450(0x184,0xd9a);
  __s[7] = __s_00;
  if (__s_00 == (void *)0x0) {
    FUN_00407df0(puVar2);
    puVar2 = __s;
    goto LAB_0048f254;
  }
  memset(__s_00,0,0x184);
  *(undefined2 *)__s[7] = *(undefined2 *)(param_1 + 0x10);
  *(undefined2 *)(__s[7] + 2) = *(undefined2 *)(param_1 + 0x18);
  *(undefined4 *)(__s[7] + 4) = *(undefined4 *)(param_1 + 0x14);
  snprintf((char *)(__s[7] + 0x12e),0x10,"%d.%d",(uint)*(ushort *)(param_1 + 0x44),
           (uint)*(ushort *)(param_1 + 0x46),uVar3,uVar4,uVar5,uVar6);
  strncpy((char *)(__s[7] + 8),(char *)(param_1 + 0x4e),0x9b);
  uVar3 = *(uint *)(param_1 + 0x1b8);
  if (1 < *(uint *)(param_1 + 0x2ac)) {
    if (*(int *)(param_1 + 0x288) == 0) {
      iVar1 = __s[7];
      goto LAB_0048f12c;
    }
    uVar3 = (uint)(*(int *)(param_1 + 0x288) == 1);
  }
  iVar1 = __s[7];
LAB_0048f12c:
  *(uint *)(iVar1 + 0x180) = uVar3;
  strcpy((char *)(__s[7] + 0xa4),"0.0.0.0");
  iVar1 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_188);
  if (iVar1 != 0) {
    FUN_00407df0(puVar2);
    FUN_00407df0(__s[7]);
    FUN_00407df0(__s);
    return 0xffffffff;
  }
  __src = local_6d;
  if (local_6d[0] == '\0') {
    __src = acStack_ae;
  }
  strncpy((char *)(__s[7] + 0xcc),__src,0x40);
  strncpy((char *)(__s[7] + 0x10d),acStack_f0,0x20);
  *(undefined4 *)(__s[7] + 0x174) = local_108;
  *(undefined4 *)(__s[7] + 0x178) = *(undefined4 *)(param_1 + 0x40);
  puVar2[4] = __s;
  FUN_004082d0(cloud_mngt_msg_mutex,0xffffffff);
  FUN_004086b0(&g_cloud_mngt_msg_list,puVar2);
  FUN_004084b0(cloud_mngt_msg_cond);
  FUN_00407f30(cloud_mngt_msg_mutex);
  FUN_00407e70();
  if (cloud_mngt_debug_switch == '\0') {
    last_ap_add_time = extraout_v1;
    return 0;
  }
  last_ap_add_time = extraout_v1;
  printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_apmngr_callback_wtp_add end\n",
         "cloud_mngt_apmngr_callback_wtp_add",0xdc2);
  return 0;
}

