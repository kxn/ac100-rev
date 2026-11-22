// func _ap_name_cmp @ 0045feb4 size=384

bool _ap_name_cmp(undefined2 param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  bool bVar4;
  char acStack_3f0 [264];
  undefined1 auStack_2e8 [78];
  char acStack_29a [650];
  
  memset(acStack_3f0,0,0x101);
  memset(auStack_2e8,0,0x2d8);
  if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_ap_name_cmp",0x102,"_ap_name_cmp");
  }
  if (param_2 == (char *)0x0) {
    bVar4 = true;
    if ((g_dhcpdef_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> Ensure %s failed.\x1b[0m\r\n","dhcp_defend","_ap_name_cmp",
             0x103,"search_value");
    }
  }
  else {
    if ((g_dhcpdef_info != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[%s]<%s():%d> ap name: %s\r\n","dhcp_defend","_ap_name_cmp",0x104,param_2);
    }
    apmngr_db_entry_get_by_id(param_1,auStack_2e8);
    strncpy(acStack_3f0,acStack_29a,0x100);
    sVar1 = strlen(acStack_3f0);
    dhcpdef_str2upper(acStack_3f0,sVar1);
    pcVar2 = strstr(acStack_3f0,param_2);
    bVar4 = pcVar2 == (char *)0x0;
  }
  return bVar4;
}

