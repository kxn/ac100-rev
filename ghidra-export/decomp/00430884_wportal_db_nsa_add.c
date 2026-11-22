// func wportal_db_nsa_add @ 00430884 size=696

int wportal_db_nsa_add(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  void *__dest;
  size_t sVar4;
  char *__s;
  undefined1 auStack_108 [104];
  undefined1 auStack_a0 [12];
  undefined1 auStack_94 [104];
  undefined1 auStack_2c [12];
  
  if (param_1 == 0) {
    return -1;
  }
  iVar1 = wportal_get_mode();
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x128) < 0) {
      return -1;
    }
    uVar2 = wserv_profile_get_max_wservice();
    if (uVar2 <= *(uint *)(param_1 + 0x128)) {
      return -1;
    }
  }
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  iVar1 = FUN_004080c0(nsa_tree,param_1);
  if (iVar1 != 0) {
    _wportal_db_nsa_copy(iVar1,param_1);
LAB_00430ad0:
    FUN_00407f30(wportal_nsa_mutex);
    return -1;
  }
  if (g_max_session <= nsa_count) {
    iVar1 = FUN_004081b0(nsa_list);
    if ((iVar1 == 0) || (iVar3 = _wportal_db_nsa_del(iVar1 + 0x74), iVar3 != 0)) goto LAB_00430ad0;
    memset(auStack_94,0,0x74);
    FUN_0051ad88(auStack_2c);
    memcpy(auStack_94,(void *)(iVar1 + 0x7a),0x65);
    iVar1 = FUN_00407fa0(username_hash_for_nsa,auStack_94);
    if ((iVar1 != 0) && (iVar3 = FUN_00407fe0(iVar1 + 0x68), iVar3 == 0)) {
      FUN_00407f40(username_hash_for_nsa,iVar1);
      FUN_00407df0(iVar1);
    }
  }
  iVar1 = FUN_00407e20(nsa_tree,param_1);
  if (iVar1 != 0) goto LAB_004309b8;
  FUN_004086b0(nsa_list,param_1);
  iVar1 = wportal_get_mode();
  if (iVar1 == 1) {
    iVar1 = *(int *)(param_1 + 0x128);
    iVar3 = vlan_list_array_for_nsa;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x128);
    iVar3 = ssid_list_array_for_nsa;
  }
  __s = (char *)(param_1 + 0x7a);
  FUN_004086b0(iVar3 + iVar1 * 0xc,param_1 + 0x110);
  memset(auStack_108,0,0x74);
  FUN_0051ad88(auStack_a0);
  memcpy(auStack_108,__s,0x65);
  __dest = (void *)FUN_00407fa0(username_hash_for_nsa,auStack_108);
  if (__dest == (void *)0x0) {
    iVar1 = -1;
    __dest = (void *)FUN_00408450(0x74,0x802);
    if (__dest != (void *)0x0) {
      sVar4 = strlen(__s);
      memcpy(__dest,__s,sVar4 + 1);
      FUN_0051ad88((int)__dest + 0x68);
      iVar3 = FUN_00408380(username_hash_for_nsa,__dest);
      if (iVar3 == 0) goto LAB_00430a78;
      FUN_00407df0(__dest);
    }
  }
  else {
LAB_00430a78:
    iVar1 = 0;
    FUN_004086b0((int)__dest + 0x68,param_1 + 0x11c);
  }
  nsa_count = nsa_count + 1;
LAB_004309b8:
  FUN_00407f30(wportal_nsa_mutex);
  return iVar1;
}

