// func dhcpv6_addrtype2str @ 005b0558 size=76

void dhcpv6_addrtype2str(char param_1,char *param_2)

{
  if (param_1 == '\0') {
    snprintf(param_2,0x10,"IP ");
    return;
  }
  if (param_1 != '\x01') {
    snprintf(param_2,0x10,"N/A");
    return;
  }
  snprintf(param_2,0x10,"MAC");
  return;
}

