// func _uac_report_read_config @ 004b37b8 size=1016

undefined4 _uac_report_read_config(void)

{
  ushort uVar3;
  int iVar1;
  int iVar2;
  int *piVar4;
  undefined4 uVar5;
  size_t __n;
  char *__s1;
  size_t __n_00;
  int *__s;
  int iVar6;
  int aiStack_160 [2];
  byte local_158 [4];
  undefined4 local_154;
  char *local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 *local_144;
  undefined4 local_140;
  undefined2 local_13c;
  undefined2 local_13a;
  undefined1 *local_138;
  int local_134 [2];
  char *local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined2 local_118;
  undefined2 local_116;
  undefined *local_114;
  undefined4 local_110;
  undefined4 local_10c;
  char *local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined2 local_f4;
  undefined2 local_f2;
  undefined2 *local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  char *local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 *local_d8;
  undefined4 local_d4;
  undefined2 local_d0;
  undefined2 local_ce;
  undefined1 *local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  char *local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 *local_b4;
  undefined4 local_b0;
  undefined2 local_ac;
  undefined2 local_aa;
  byte *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  char *local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  ushort local_88;
  undefined2 local_86;
  int *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  char *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined2 local_64;
  undefined2 local_62;
  undefined2 *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 *local_3c;
  undefined4 local_38;
  int *local_30;
  
  local_158[0] = 0;
  local_158[1] = 0;
  local_158[2] = 0;
  local_158[3] = 0;
  uVar3 = apmngr_db_get_group_max();
  __n = (uint)uVar3 << 1;
  __n_00 = (uint)uVar3 * 4;
  DAT_00767d58 = (undefined2 *)FUN_00408450(__n,0x77);
  local_154 = 0;
  local_14c = 0;
  local_138 = &report_ctx;
  local_140 = 10;
  local_f8 = 10;
  local_e8 = 3;
  local_148 = 0;
  local_134[0] = 0;
  local_134[1] = 1;
  local_150 = "state";
  local_128 = 1;
  local_118 = 1;
  local_10c = 2;
  __s = (int *)((int)aiStack_160 - (__n_00 + 0xe & 0xfffffff8));
  local_144 = &state_map;
  local_f4 = 1;
  local_13c = 1;
  local_13a = 1;
  local_f2 = 2;
  local_124 = 0;
  local_120 = 0;
  local_12c = "server_address";
  local_11c = 0;
  local_116 = 0xfb;
  local_110 = 0;
  local_104 = 0;
  local_100 = 0;
  local_114 = &DAT_00767c5a;
  local_fc = 0;
  local_ec = 0;
  local_108 = "server_port";
  local_f0 = &DAT_00767d56;
  local_e4 = "protocol";
  local_e0 = 0;
  local_c4 = 4;
  local_bc = 3;
  local_d8 = &protocol_map;
  local_ac = 4;
  local_98 = 3;
  local_86 = 4;
  local_cc = &DAT_00767c59;
  local_d4 = 10;
  local_d0 = 1;
  local_ce = 1;
  local_b4 = &content_map;
  local_a8 = local_158;
  local_b0 = 10;
  local_aa = 1;
  local_a0 = 5;
  local_8c = 10;
  local_7c = 6;
  local_68 = 10;
  local_dc = 0;
  local_c8 = 0;
  local_78 = "interval";
  local_c0 = "content";
  local_b8 = 0;
  local_a4 = 0;
  local_9c = "apgroup";
  local_94 = 0;
  local_90 = 0;
  local_80 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_64 = 1;
  local_60 = &DAT_00767d5e;
  local_40 = 1;
  local_58 = 7;
  local_44 = 10;
  local_62 = 2;
  local_3e = 2;
  local_54 = "max_load";
  local_3c = &DAT_00767d60;
  local_5c = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_38 = 0;
  local_88 = uVar3;
  local_84 = __s;
  memset(DAT_00767d58,0,__n);
  memset(__s,0,__n_00);
  iVar1 = FUN_00408120("apmng_report","settings",&local_154,8);
  if (iVar1 == 0) {
    piVar4 = local_134;
    iVar6 = 0;
    local_30 = (int *)&stack0xffffffec;
    iVar1 = 0;
    while (piVar4 != local_30) {
      __s1 = (char *)piVar4[-7];
      iVar2 = strcmp(__s1,"content");
      if (iVar2 == 0) {
        iVar1 = *piVar4;
        piVar4 = piVar4 + 9;
      }
      else {
        iVar2 = strcmp(__s1,"apgroup");
        if (iVar2 == 0) {
          iVar6 = *piVar4;
          piVar4 = piVar4 + 9;
        }
        else {
          piVar4 = piVar4 + 9;
        }
      }
    }
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
      DAT_00767d5c = DAT_00767d5c | local_158[iVar2];
    }
    for (iVar1 = 0; iVar1 < iVar6; iVar1 = iVar1 + 1) {
      if (*__s == -1) {
        *DAT_00767d58 = 1;
        DAT_00767d58[1] = 1;
        return 0;
      }
      DAT_00767d58[*__s] = 1;
      __s = __s + 1;
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 0xffffffff;
    if (report_err_switch != 0) {
      printf("[REPORT_ERROR]%s()/line %d : _uac_report_read_config uci req parse failed.\n",
             "_uac_report_read_config",0x8a);
    }
  }
  return uVar5;
}

