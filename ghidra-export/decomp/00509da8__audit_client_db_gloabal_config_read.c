// func _audit_client_db_gloabal_config_read @ 00509da8 size=608

undefined4 _audit_client_db_gloabal_config_read(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_128;
  int local_124;
  int local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined1 auStack_110 [32];
  char acStack_f0 [40];
  undefined4 local_c8;
  char *local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 *local_b8;
  undefined4 local_b4;
  undefined2 local_b0;
  undefined2 local_ae;
  undefined4 *local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  char *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined2 local_8c;
  undefined2 local_8a;
  char *local_88;
  undefined4 local_84;
  undefined4 local_80;
  char *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 *local_70;
  undefined4 local_6c;
  undefined2 local_68;
  undefined2 local_66;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  char *local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  int *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  char *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  int *local_1c;
  undefined4 local_18;
  
  local_11c = 0;
  local_120 = 0;
  local_124 = 0;
  local_128 = 0;
  memcpy(auStack_110,&PTR_s_local_006bc740,0x20);
  local_118 = 2;
  local_ac = &local_11c;
  local_80 = 2;
  local_c8 = 0;
  local_c4 = "enable";
  local_7c = "server_type";
  local_70 = &local_118;
  local_c0 = 0;
  local_64 = &local_120;
  local_a8 = 0;
  local_b8 = &onoff_map;
  local_5c = 3;
  local_a0 = "remote_ip";
  local_98 = 0;
  local_bc = 1;
  local_b4 = 10;
  local_ae = 4;
  local_8a = 0x28;
  local_6c = 10;
  local_66 = 4;
  local_b0 = 1;
  local_a4 = 1;
  local_9c = 1;
  local_94 = 0;
  local_90 = 0;
  local_8c = 1;
  local_84 = 0;
  local_78 = 0;
  local_74 = 1;
  local_68 = 1;
  local_60 = 0;
  local_58 = "sniffing_report_interval";
  local_42 = 4;
  local_40 = &local_124;
  local_48 = 10;
  local_34 = "sniffing_report_max";
  local_24 = 10;
  local_1c = &local_128;
  local_54 = 0;
  local_50 = 1;
  local_4c = 0;
  local_44 = 1;
  local_3c = 0;
  local_38 = 4;
  local_30 = 0;
  local_2c = 1;
  local_28 = 0;
  local_20 = 1;
  local_1e = 4;
  local_18 = 0;
  local_114 = auStack_110;
  local_88 = acStack_f0;
  iVar1 = FUN_00408120("apmng_audit","settings",&local_c8,5);
  if (iVar1 == 0) {
    audit_server = local_11c;
    DAT_007688f8 = local_120;
    if (local_120 == 1) {
      snprintf(acStack_f0,0x28,"%s","127.0.0.1");
    }
    FUN_0051a7a8(acStack_f0,&DAT_007688e4);
    uVar2 = 0;
    DAT_007688fc = 0x3c;
    if (local_124 < 0x3d) {
      DAT_007688fc = local_124;
    }
    DAT_00768900 = 500;
    if (local_128 < 0x1f5) {
      DAT_00768900 = local_128;
    }
  }
  else {
    uVar2 = 0xffffffff;
    if (audit_err_switch != 0) {
      printf("[AUDIT_ERR]%s()/%d uci req parse failed.\n","_audit_client_db_gloabal_config_read",
             0x59);
    }
  }
  return uVar2;
}

