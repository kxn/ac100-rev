// func mesh_global_config_init @ 004ba47c size=1612

/* WARNING: Removing unreachable block (ram,0x004ba94c) */

undefined4 mesh_global_config_init(void)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  char local_6c0 [4];
  undefined4 local_6bc;
  undefined4 local_6b8;
  undefined4 local_6b4;
  undefined4 local_6b0;
  undefined2 local_6ac;
  char acStack_6a8 [52];
  undefined1 auStack_674 [64];
  char acStack_634 [128];
  undefined1 auStack_5b4 [33];
  undefined1 auStack_593 [64];
  undefined1 auStack_553 [35];
  undefined4 local_530;
  char *local_52c;
  undefined4 local_528;
  undefined4 local_524;
  undefined4 *local_520;
  undefined4 local_51c;
  undefined2 local_518;
  undefined2 local_516;
  undefined4 *local_514;
  undefined4 local_510;
  undefined4 local_50c;
  char *local_508;
  undefined4 local_504;
  undefined4 local_500;
  undefined4 local_4fc;
  undefined4 local_4f8;
  undefined2 local_4f4;
  undefined2 local_4f2;
  undefined1 *local_4f0;
  int local_4ec;
  undefined4 local_4e8;
  char *local_4e4;
  undefined4 local_4e0;
  undefined4 local_4dc;
  undefined4 local_4d8;
  undefined4 local_4d4;
  undefined2 local_4d0;
  undefined2 local_4ce;
  undefined1 *local_4cc;
  int local_4c8;
  undefined4 local_4c4;
  char *local_4c0;
  undefined4 local_4bc;
  undefined4 local_4b8;
  undefined4 local_4b4;
  undefined4 local_4b0;
  undefined2 local_4ac;
  undefined2 local_4aa;
  undefined1 *local_4a8;
  int local_4a4;
  undefined4 local_4a0;
  char *local_49c;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 *local_490;
  undefined4 local_48c;
  undefined2 local_488;
  undefined2 local_486;
  undefined4 *local_484;
  undefined4 local_480;
  undefined4 local_47c;
  char *local_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined2 local_464;
  undefined2 local_462;
  undefined4 *local_460;
  undefined4 local_45c;
  undefined4 local_458;
  char *local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined2 local_440;
  undefined2 local_43e;
  char *local_43c;
  undefined4 local_438;
  char acStack_434 [1028];
  char *local_30;
  
  local_6b0 = 0;
  local_6ac = 0;
  memset(acStack_6a8,0,0x32);
  memset(acStack_634,0,0x80);
  memset(auStack_5b4,0,0x82);
  local_6b4 = 0;
  local_6b8 = 0;
  local_6bc = 1;
  memset(acStack_434,0,0x400);
  local_6c0[0] = '\x02';
  iVar1 = FUN_005135a8(&local_6b0);
  if (iVar1 == 0) {
    iVar1 = FUN_00408040(acStack_6a8,0x32);
    if (iVar1 != 0) {
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d get product name failed.\n","mesh_global_config_init",200);
      }
      strcpy(acStack_6a8,"TL-AC10000");
    }
    snprintf(acStack_634,0x80,"[%02x:%02x:%02x:%02x:%02x:%02x]+%s+ssid",local_6b0 >> 0x18,
             (uint)local_6b0._1_1_,local_6b0 >> 8 & 0xff,local_6b0 & 0xff,(uint)local_6ac._0_1_,
             (uint)(byte)local_6ac,acStack_6a8);
    sVar2 = strlen(acStack_634);
    FUN_004b6c38(acStack_634,sVar2,&dft_backhaul_info,0x10);
    snprintf(acStack_634,0x80,"[%02x:%02x:%02x:%02x:%02x:%02x]+%s+keyPrefix",local_6b0 >> 0x18,
             local_6b0 >> 0x10 & 0xff,local_6b0 >> 8 & 0xff,local_6b0 & 0xff,(uint)local_6ac._0_1_,
             (uint)(byte)local_6ac,acStack_6a8);
    sVar2 = strlen(acStack_634);
    FUN_004b6c38(acStack_634,sVar2,&DAT_00767fe1,0x10);
    snprintf(acStack_634,0x80,"[%02x:%02x:%02x:%02x:%02x:%02x]+%s+keySuffix",local_6b0 >> 0x18,
             local_6b0 >> 0x10 & 0xff,local_6b0 >> 8 & 0xff,local_6b0 & 0xff,(uint)local_6ac._0_1_,
             (uint)(byte)local_6ac,acStack_6a8);
    sVar2 = strlen(acStack_634);
    FUN_004b6c38(acStack_634,sVar2,&DAT_00768001,0xf);
    DAT_0076801f = 0x74;
    DAT_00768020 = 0;
    snprintf(acStack_634,0x80,"[%02x:%02x:%02x:%02x:%02x:%02x]+%s+token",local_6b0 >> 0x18,
             local_6b0 >> 0x10 & 0xff,local_6b0 >> 8 & 0xff,local_6b0 & 0xff,(uint)local_6ac._0_1_,
             (uint)(byte)local_6ac,acStack_6a8);
    sVar2 = strlen(acStack_634);
    FUN_004b6c38(acStack_634,sVar2,&DAT_00768021,0x10);
    mesh_db_mesh_wan_status_set((int)local_6c0[0]);
    local_530 = 0;
    local_516 = 4;
    local_514 = &local_6b4;
    local_4e4 = "backhaul_key";
    local_4ce = 0x40;
    local_4cc = auStack_593;
    local_528 = 0;
    local_508 = "backhaul_ssid";
    local_4f0 = auStack_5b4;
    local_52c = "enable";
    local_4c4 = 3;
    local_510 = 0;
    local_524 = 1;
    local_51c = 10;
    local_518 = 1;
    local_520 = &onoff_map;
    local_50c = 1;
    local_504 = 1;
    local_4f4 = 1;
    local_4f2 = 0x21;
    local_4e8 = 2;
    local_4e0 = 1;
    local_4d0 = 1;
    local_4c0 = "backhaul_token";
    local_4bc = 1;
    local_500 = 0;
    local_4fc = 0;
    local_4f8 = 0;
    local_4ec = 0;
    local_4dc = 0;
    local_4d8 = 0;
    local_4d4 = 0;
    local_4c8 = 0;
    local_4b8 = 0;
    local_4aa = 0x21;
    local_4a8 = auStack_553;
    local_490 = &onoff_map;
    local_484 = &local_6b8;
    local_4a0 = 4;
    local_486 = 4;
    local_462 = 4;
    local_460 = &local_6bc;
    local_47c = 5;
    local_4ac = 1;
    local_458 = 6;
    local_49c = "re_auto_switch";
    local_494 = 1;
    local_48c = 10;
    local_488 = 1;
    local_478 = "bh_work_mode";
    local_468 = 10;
    local_464 = 2;
    local_454 = "wan_status";
    local_444 = 10;
    local_440 = 2;
    local_4b4 = 0;
    local_4b0 = 0;
    local_4a4 = 0;
    local_498 = 0;
    local_480 = 0;
    local_474 = 0;
    local_470 = 0;
    local_46c = 0;
    local_45c = 0;
    local_450 = 0;
    local_44c = 0;
    local_448 = 0;
    local_43e = 1;
    local_43c = local_6c0;
    local_438 = 0;
    local_30 = local_43c;
    iVar1 = FUN_00408120("apmng_mesh","settings",&local_530,7);
    if (iVar1 == 0) {
      memcpy(auStack_674,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",0x3e);
      iVar1 = 0;
      do {
        uVar3 = random();
        iVar5 = iVar1 + 1;
        (&DAT_00767f44)[iVar1] = auStack_674[uVar3 % 0x3e];
        iVar1 = iVar5;
      } while (iVar5 != 6);
      DAT_00767f4a = 0;
      mesh_db_mesh_enable_set(local_6b4);
      mesh_db_mesh_wan_status_set((int)local_6c0[0]);
      mesh_db_policy_set();
      mesh_db_policy_mask_set();
      if (((local_4ec == 0) || (local_4c8 == 0)) || (local_4a4 == 0)) {
        mesh_db_backhaul_info_set(&dft_backhaul_info);
        snprintf(acStack_434,0x400,
                 "uci set %s.%s.%s=%s;uci set %s.%s.%s=%s;uci set %s.%s.%s=%s;uci commit %s",
                 "apmng_mesh","settings","backhaul_ssid",&DAT_00767ebd,"apmng_mesh","settings",
                 "backhaul_key",&DAT_00767ede,"apmng_mesh","settings","backhaul_token",&DAT_00767f1e
                 ,"apmng_mesh");
        system(acStack_434);
      }
      else {
        mesh_db_backhaul_info_set(auStack_5b4);
      }
      mesh_db_re_auto_switch_set(local_6b8);
      mesh_db_bh_work_mode_set(local_6bc);
      return 0;
    }
    if (mesh_err_switch != '\0') {
      __format = "[MESH_ERROR]%s()/%d uci req parse failed.\n";
      uVar4 = 0xea;
      goto LAB_004baa68;
    }
  }
  else if (mesh_err_switch != '\0') {
    __format = "[MESH_ERROR]%s()/%d Get dev mac failed\n";
    uVar4 = 0xc3;
LAB_004baa68:
    printf(__format,"mesh_global_config_init",uVar4);
    return 0xffffffff;
  }
  return 0xffffffff;
}

