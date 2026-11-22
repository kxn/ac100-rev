// func addr2str @ 005afd70 size=184

void addr2str(char param_1,byte *param_2,char *param_3)

{
  if (param_1 == '\0') {
    snprintf(param_3,0x10,"%d.%d.%d.%d",(uint)*param_2,(uint)param_2[1],(uint)param_2[2],
             (uint)param_2[3]);
  }
  else {
    if (param_1 != '\x01') {
      snprintf(param_3,0x12,"N/A");
      return;
    }
    snprintf(param_3,0x12,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*param_2,(uint)param_2[1],
             (uint)param_2[2],(uint)param_2[3],(uint)param_2[4],(uint)param_2[5]);
  }
  return;
}

