// func dhcpdef_addrtype2str @ 004671b4 size=92

void dhcpdef_addrtype2str(char param_1,char *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == '\x01') {
    snprintf(param_2,0x10,"MAC");
    return;
  }
  if (param_1 == '\x02') {
    uVar1 = 6;
  }
  else {
    uVar1 = 4;
    if (param_1 != '\0') {
      snprintf(param_2,0x10,"N/A",4);
      return;
    }
  }
  snprintf(param_2,0x10,"IP(%d)",uVar1);
  return;
}

