// func dhcpdef_addr2str @ 00467210 size=244

void dhcpdef_addr2str(char param_1,byte *param_2,char *param_3)

{
  undefined1 auStack_18 [16];
  
  if (param_1 == '\x01') {
    snprintf(param_3,0x12,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
  }
  else if (param_1 == '\x02') {
    memcpy(auStack_18,param_2,0x10);
    inet_ntop(10,auStack_18,param_3,0x28);
  }
  else if (param_1 == '\0') {
    snprintf(param_3,0x10,"%d.%d.%d.%d",(uint)*param_2,(uint)param_2[1],(uint)param_2[2],
             (uint)param_2[3]);
  }
  else {
    snprintf(param_3,0x28,"N/A");
  }
  return;
}

