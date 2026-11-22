// func apmngr_aplog_config_set @ 0052b6a8 size=416

undefined4 apmngr_aplog_config_set(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_stack_00000024;
  int in_stack_00000028;
  undefined1 local_34 [28];
  
  iVar3 = in_stack_00000024;
  bVar1 = g_apmngr_ac_log_switch != param_1;
  if (param_1 == 0) {
    g_apmngr_ac_log_level = 4;
  }
  else {
    bVar1 = bVar1 || g_apmngr_ac_log_level != param_2;
    g_apmngr_ac_log_level = param_2;
  }
  bVar2 = bVar1 || g_apmngr_remote_server_switch != param_3;
  g_apmngr_ac_log_switch = param_1;
  if (param_3 == 0) {
    g_apmngr_remote_server = 0;
    g_apmngr_remote_log_level = 4;
    DAT_007c5840 = 0;
    DAT_007c5844 = 0;
    DAT_007c5848 = 0;
    DAT_007c584c = 0;
    g_apmngr_remote_report_interval = 0x14;
    g_apmngr_remote_server_switch = param_3;
  }
  else {
    if (bVar1 || g_apmngr_remote_server_switch != param_3) {
      bVar2 = true;
      g_apmngr_remote_server_switch = param_3;
    }
    else {
      bVar2 = true;
      g_apmngr_remote_server_switch = param_3;
      if (g_apmngr_remote_log_level == param_4) {
        for (uVar4 = 0; uVar4 < 0x14; uVar4 = uVar4 + 1) {
          local_34[uVar4] = (&stack0x00000010)[uVar4];
        }
        iVar5 = FUN_004085c0(g_apmngr_remote_server,DAT_007c5840,DAT_007c5844,DAT_007c5848,
                             DAT_007c584c);
        if (iVar5 == 0) {
          bVar2 = true;
        }
        else {
          bVar2 = g_apmngr_remote_report_interval != iVar3;
        }
      }
    }
    g_apmngr_remote_log_level = param_4;
    memcpy(&g_apmngr_remote_server,&stack0x00000010,0x14);
    g_apmngr_remote_report_interval = iVar3;
  }
  if ((bVar2) && (in_stack_00000028 != 0)) {
    apmngr_pkt_aplog_config_pkt_send_to_all();
  }
  return 0;
}

