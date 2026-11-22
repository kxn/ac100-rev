// func _wserv_print_hash_entry @ 005e9730 size=1

void _wserv_print_hash_entry(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  puts("#####################################################################");
  printf("id        = %d\n",*(undefined4 *)(param_1 + 0x80));
  if (*(int *)(param_1 + 0x11b) == 0) {
    pcVar3 = "disable";
  }
  else {
    pcVar3 = "enable";
  }
  printf("enable    = %s\n",pcVar3);
  if (*(int *)(param_1 + 0x11f) == 0) {
    pcVar3 = "disable";
  }
  else {
    pcVar3 = "enable";
  }
  printf("auto_bind = %s\n",pcVar3);
  printf("default_bind_freq = 0x%04x\n",(uint)*(ushort *)(param_1 + 0x125));
  printf("default_bind_vlan = %d\n",(uint)*(ushort *)(param_1 + 0x123));
  if (*(int *)(param_1 + 0x162) == 0) {
    pcVar3 = "disable";
  }
  else {
    pcVar3 = "enable";
  }
  printf("isolation = %s\n",pcVar3);
  if (*(int *)(param_1 + 0x166) == 0) {
    pcVar3 = "enable";
  }
  else {
    pcVar3 = "disable";
  }
  printf("ssid hidden = %s\n",pcVar3);
  printf("encode    = ");
  if (*(int *)(param_1 + 300) == 1) {
    pcVar3 = "UTF-8";
  }
  else if (*(int *)(param_1 + 300) == 2) {
    pcVar3 = "GBK";
  }
  else {
    pcVar3 = "unknown";
  }
  puts(pcVar3);
  printf("ssid      = %s\n",param_1 + 0x130);
  printf("ssid_id   = %s\n",param_1);
  printf("decrible  = %s\n",param_1 + 0x84);
  printf("sec_type  = ");
  iVar2 = *(int *)(param_1 + 0x16a);
  if (iVar2 == 0) {
    pcVar3 = "close";
  }
  else if (iVar2 == 1) {
    pcVar3 = "wpa-psk/wpa2-psk";
  }
  else if (iVar2 == 2) {
    pcVar3 = "wpa/wpa2";
  }
  else if (iVar2 == 4) {
    pcVar3 = "wpa2-psk/wpa3-sae";
  }
  else {
    pcVar3 = "unknown";
  }
  puts(pcVar3);
  iVar2 = *(int *)(param_1 + 0x16a);
  if ((iVar2 == 1) || (iVar2 == 4)) {
    printf("wpa_psk.auth_type        = ");
    iVar2 = *(int *)(param_1 + 0x16e);
    if (iVar2 == 1) {
      pcVar3 = "WPA";
    }
    else if (iVar2 == 2) {
      pcVar3 = "WPA2";
    }
    else if (iVar2 == 3) {
      pcVar3 = "AUTO";
    }
    else {
      pcVar3 = "unknown";
    }
    puts(pcVar3);
    printf("wpa_psk.encrypt_alg      = ");
    iVar2 = *(int *)(param_1 + 0x172);
    if (iVar2 == 0) {
      pcVar3 = "AUTO";
    }
    else if (iVar2 == 1) {
      pcVar3 = "TKIP";
    }
    else if (iVar2 == 2) {
      pcVar3 = "AES";
    }
    else {
      pcVar3 = "unknown";
    }
    puts(pcVar3);
    printf("wpa_psk.key_update_intv  = %d\n",*(undefined4 *)(param_1 + 0x176));
    iVar2 = param_1 + 0x17a;
    pcVar3 = "wpa_psk.psk              = %s\n";
  }
  else {
    if (iVar2 != 2) {
      cVar1 = *(char *)(param_1 + 0x1f6);
      goto LAB_005e937c;
    }
    printf("wpa.auth_type            = ");
    iVar2 = *(int *)(param_1 + 0x16e);
    if (iVar2 == 1) {
      pcVar3 = "WPA";
    }
    else if (iVar2 == 2) {
      pcVar3 = "WPA2";
    }
    else if (iVar2 == 3) {
      pcVar3 = "AUTO";
    }
    else {
      pcVar3 = "unknown";
    }
    puts(pcVar3);
    printf("wpa_psk.encrypt_alg      = ");
    iVar2 = *(int *)(param_1 + 0x172);
    if (iVar2 == 0) {
      pcVar3 = "AUTO";
    }
    else if (iVar2 == 1) {
      pcVar3 = "TKIP";
    }
    else if (iVar2 == 2) {
      pcVar3 = "AES";
    }
    else {
      pcVar3 = "unknown";
    }
    puts(pcVar3);
    printf("wpa.key_update_intv      = %d\n",*(undefined4 *)(param_1 + 0x176));
    printf("wpa.radius_serv          = %s\n",param_1 + 0x17a);
    printf("wpa.radius_port          = %d\n",*(undefined4 *)(param_1 + 0x1a2));
    printf("wpa.radius_acct_port     = %d\n",*(undefined4 *)(param_1 + 0x1a6));
    iVar2 = param_1 + 0x1aa;
    pcVar3 = "wpa.radius_pwd           = %s\n";
  }
  printf(pcVar3,iVar2);
  cVar1 = *(char *)(param_1 + 0x1f6);
LAB_005e937c:
  if (cVar1 == '\0') {
    pcVar3 = "disable";
  }
  else {
    pcVar3 = "enable";
  }
  printf("bw_enable        = %s\n",pcVar3);
  printf("bw_mode          = %d\n",(uint)*(byte *)(param_1 + 0x1f7));
  printf("upstream_rate    = %u\n",*(undefined4 *)(param_1 + 0x1ee));
  printf("downstream_rate  = %u\n",*(undefined4 *)(param_1 + 0x1f2));
  if (*(char *)(param_1 + 0x1fa) == '\x01') {
    pcVar3 = "enable";
  }
  else {
    pcVar3 = "disable";
  }
  printf("igmpSnpEnable    = %s\n",pcVar3);
  printf("igmpDropUnknown  = %u\n",(uint)*(byte *)(param_1 + 0x1fb));
  printf("igmp2GRate       = %u\n",(uint)*(ushort *)(param_1 + 0x1fc));
  printf("igmp5GRate       = %u\n",(uint)*(ushort *)(param_1 + 0x1fe));
  printf("igmpQueryInterval= %u\n",(uint)*(ushort *)(param_1 + 0x200));
  printf("igmpMaxRespTime  = %u\n",(uint)*(byte *)(param_1 + 0x202));
  printf("igmpSnpSwitch    = %u\n",(uint)*(byte *)(param_1 + 0x203));
  printf("igmpQuerySwitch  = %u\n",(uint)*(byte *)(param_1 + 0x204));
  printf("ssidPortalSwitch = %u\n",(uint)*(byte *)(param_1 + 0x127));
  if (*(int *)(param_1 + 0x128) == 0) {
    pcVar3 = "disable";
  }
  else {
    pcVar3 = "enable";
  }
  printf("mlo_switch       = %s\n",pcVar3);
  return;
}

