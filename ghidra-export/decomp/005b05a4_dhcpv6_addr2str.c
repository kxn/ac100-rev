// func dhcpv6_addr2str @ 005b05a4 size=192

void dhcpv6_addr2str(char param_1,byte *param_2,char *param_3,socklen_t param_4)

{
  undefined1 auStack_20 [20];
  
  if (param_1 == '\0') {
    memcpy(auStack_20,param_2,0x10);
    inet_ntop(10,auStack_20,param_3,param_4);
  }
  else if (param_1 == '\x01') {
    snprintf(param_3,0x12,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
  }
  else {
    snprintf(param_3,0x12,"N/A");
  }
  return;
}

