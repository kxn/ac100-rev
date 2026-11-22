// func _wserv_init_rd @ 005e8cc8 size=188

void _wserv_init_rd(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  void *__s;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  iVar4 = 0;
  __s = (void *)param_1[1];
  iVar2 = rdmngr_profile_get_max_wlan_per_rd();
  memset(__s,0,iVar2 * 6);
  *param_1 = 0xffffffff;
  while( true ) {
    uVar3 = rdmngr_profile_get_max_wlan_per_rd();
    bVar1 = uVar3 <= uVar5;
    uVar5 = uVar5 + 1;
    if (bVar1) break;
    *(undefined1 *)(param_1[1] + iVar4) = 0;
    *(char *)(param_1[1] + iVar4 + 1) = (char)uVar5;
    *(undefined2 *)(param_1[1] + iVar4 + 2) = 0xffff;
    iVar2 = param_1[1] + iVar4;
    iVar4 = iVar4 + 6;
    *(undefined2 *)(iVar2 + 4) = 0xffff;
  }
  return;
}

