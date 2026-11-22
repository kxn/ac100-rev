// func _wportal_aut_dae_check @ 0040b948 size=1280

undefined4 _wportal_aut_dae_check(int param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char *__format;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *local_37c;
  uint local_378;
  char *local_374;
  undefined4 local_370;
  undefined4 local_36c;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  undefined4 local_354;
  undefined4 local_350;
  undefined4 local_34c;
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328;
  undefined4 local_324;
  undefined4 local_320;
  undefined4 local_31c;
  undefined4 local_318;
  undefined4 local_314;
  undefined1 auStack_310 [64];
  undefined1 auStack_2d0 [64];
  undefined1 auStack_290 [64];
  char acStack_250 [256];
  undefined1 auStack_150 [222];
  undefined1 auStack_72 [66];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_324 = 0;
  local_320 = 0;
  local_31c = 0;
  local_318 = 0;
  local_314 = 0;
  memset(acStack_250,0,0xfe);
  local_338 = 0;
  local_334 = 0;
  local_330 = 0;
  local_32c = 0;
  local_328 = 0;
  local_34c = 0;
  local_348 = 0;
  local_344 = 0;
  local_340 = 0;
  local_33c = 0;
  local_360 = 0;
  local_35c = 0;
  local_358 = 0;
  local_354 = 0;
  local_350 = 0;
  memset(auStack_290,0,0x40);
  memset(auStack_2d0,0,0x40);
  memset(auStack_310,0,0x40);
  memset(auStack_150,0,0x134);
  iVar1 = wportal_db_rds_srv_get_by_index(*(undefined4 *)(param_1 + 0x158),auStack_150);
  if (iVar1 != 0) {
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[WPORTAL_DBG]%s()/%d Cannot find radius server %d\n\n","_wportal_aut_dae_check",0x1988,
           *(undefined4 *)(param_1 + 0x158));
    return 0xffffffff;
  }
  for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
    *(char *)((int)&local_37c + uVar2) = param_2[uVar2 + 0x184];
  }
  iVar1 = FUN_004085c0(local_30,local_2c,local_28,local_24,local_20);
  if (iVar1 == 0) {
    FUN_00408560(&local_2c,local_30._0_1_,&local_34c);
    puVar5 = auStack_290;
    FUN_00408560(param_2 + 0x188,param_2[0x184],&local_360);
    local_378 = 0x40;
    local_374 = "---";
    local_37c = puVar5;
    FUN_00408190(local_34c,local_348,local_344,local_340,local_33c);
    local_37c = auStack_2d0;
    local_378 = 0x40;
    local_374 = "---";
    FUN_00408190(local_360,local_35c,local_358,local_354,local_350);
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    puVar6 = auStack_2d0;
    __format = "[WPORTAL_DBG]%s()/%d radius ip is %s not same as remote ip %s.\n\n";
    uVar4 = 0x1992;
LAB_0040bb58:
    printf(__format,"_wportal_aut_dae_check",uVar4,puVar5,puVar6);
    return 0xffffffff;
  }
  FUN_0051a7a8(auStack_72,&local_338);
  if (param_2[0x198] == '\0') {
    cVar3 = param_2[0x82];
  }
  else {
    iVar1 = FUN_00407eb0(*(undefined4 *)(param_2 + 0x198),*(undefined4 *)(param_2 + 0x19c),
                         *(undefined4 *)(param_2 + 0x1a0),*(undefined4 *)(param_2 + 0x1a4),
                         *(undefined4 *)(param_2 + 0x1a8));
    if (iVar1 == 0) {
      cVar3 = param_2[0x82];
    }
    else {
      for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
        *(undefined1 *)((int)&local_37c + uVar2) = *(undefined1 *)((int)&local_338 + uVar2);
      }
      iVar1 = FUN_004085c0(*(undefined4 *)(param_2 + 0x198),*(undefined4 *)(param_2 + 0x19c),
                           *(undefined4 *)(param_2 + 0x1a0),*(undefined4 *)(param_2 + 0x1a4),
                           *(undefined4 *)(param_2 + 0x1a8));
      if (iVar1 == 0) {
        memset(auStack_310,0,0x40);
        local_37c = auStack_310;
        local_378 = 0x40;
        local_374 = "---";
        FUN_00408190(*(undefined4 *)(param_2 + 0x198),*(undefined4 *)(param_2 + 0x19c),
                     *(undefined4 *)(param_2 + 0x1a0),*(undefined4 *)(param_2 + 0x1a4),
                     *(undefined4 *)(param_2 + 0x1a8));
        if (wportal_debug_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        puVar6 = auStack_310;
        __format = "[WPORTAL_DBG]%s()/%d radius nas ip %s is not same as remote nas ip: %s\n\n";
        uVar4 = 0x199d;
        puVar5 = auStack_72;
        goto LAB_0040bb58;
      }
      cVar3 = param_2[0x82];
    }
  }
  if (cVar3 == '\0') {
    cVar3 = *param_2;
  }
  else {
    local_37c = (undefined1 *)(uint)*(byte *)(param_1 + 0xf);
    local_378 = (uint)*(byte *)(param_1 + 0x10);
    local_374 = (char *)(uint)*(byte *)(param_1 + 0x11);
    local_36c = *(undefined4 *)(param_1 + 0x164);
    local_370 = *(undefined4 *)(param_1 + 0x160);
    sprintf(acStack_250,"%02x%02x%02x%02x%02x%02x-%llu",(uint)*(byte *)(param_1 + 0xc),
            (uint)*(byte *)(param_1 + 0xd),(uint)*(byte *)(param_1 + 0xe));
    iVar1 = strcmp(param_2 + 0x82,acStack_250);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    cVar3 = *param_2;
  }
  if ((cVar3 != '\0') && (iVar1 = strcmp(param_2,(char *)(param_1 + 0xa3)), iVar1 != 0)) {
    return 0xffffffff;
  }
  if (g_portal_auth_mode == 1) {
    iVar1 = *(int *)(param_2 + 0x180);
  }
  else {
    if (g_portal_auth_mode != 0) {
      iVar1 = *(int *)(param_2 + 0x7c);
      goto LAB_0040bbf4;
    }
    iVar1 = *(int *)(param_2 + 0x180);
  }
  if (iVar1 == -1) {
    iVar1 = *(int *)(param_2 + 0x7c);
  }
  else {
    if (iVar1 != *(int *)(param_1 + 0x14)) {
      return 0xffffffff;
    }
    iVar1 = *(int *)(param_2 + 0x7c);
  }
LAB_0040bbf4:
  if (((iVar1 != 0) || ((*(uint *)(param_2 + 0x80) & 0xffff0000) != 0)) &&
     (iVar1 = memcmp(param_2 + 0x7c,(void *)(param_1 + 0xc),6), iVar1 != 0)) {
    return 0xffffffff;
  }
  uVar4 = 0;
  FUN_0051a7a8(param_1 + 0x58,&local_324);
  iVar1 = FUN_00407eb0(*(undefined4 *)(param_2 + 0x68),*(undefined4 *)(param_2 + 0x6c),
                       *(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x74),
                       *(undefined4 *)(param_2 + 0x78));
  if (iVar1 != 0) {
    for (uVar2 = 0; uVar2 < 0x14; uVar2 = uVar2 + 1) {
      *(undefined1 *)((int)&local_37c + uVar2) = *(undefined1 *)((int)&local_324 + uVar2);
    }
    uVar4 = 0xffffffff;
    iVar1 = FUN_004085c0(*(undefined4 *)(param_2 + 0x68),*(undefined4 *)(param_2 + 0x6c),
                         *(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x74),
                         *(undefined4 *)(param_2 + 0x78));
    if (iVar1 != 0) {
      uVar4 = 0;
    }
  }
  return uVar4;
}

