// func _ap_mac_cmp @ 0045fb70 size=404

bool _ap_mac_cmp(undefined2 param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  char acStack_3f0 [264];
  undefined1 auStack_2e8 [72];
  byte local_2a0;
  byte local_29f;
  byte local_29e;
  byte local_29d;
  byte local_29c;
  byte local_29b;
  
  memset(acStack_3f0,0,0x101);
  memset(auStack_2e8,0,0x2d8);
  if ((g_dhcpdef_info != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_ap_mac_cmp",0x134,"_ap_mac_cmp");
  }
  if (param_2 == (char *)0x0) {
    bVar4 = true;
    if ((g_dhcpdef_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_ap_mac_cmp",
             0x135,"search_value");
    }
  }
  else {
    apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    snprintf(acStack_3f0,0x12,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)local_2a0,(uint)local_29f,
             (uint)local_29e,(uint)local_29d,(uint)local_29c,(uint)local_29b);
    sVar1 = strlen(acStack_3f0);
    dhcpdef_str2upper(acStack_3f0,sVar1);
    iVar2 = strcmp(acStack_3f0,"00-00-00-00-00-00");
    if (iVar2 == 0) {
      snprintf(acStack_3f0,0x101,"---");
    }
    pcVar3 = strstr(acStack_3f0,param_2);
    bVar4 = pcVar3 == (char *)0x0;
  }
  return bVar4;
}

