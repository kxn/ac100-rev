// func mesh_db_uplink_type_str_get @ 004b8404 size=68

char * mesh_db_uplink_type_str_get(uint param_1)

{
  char *pcVar1;
  char *local_10 [4];
  
  local_10[1] = "wired";
  pcVar1 = "unknown";
  local_10[0] = "unknown";
  local_10[2] = "wireless";
  if (param_1 < 3) {
    pcVar1 = local_10[param_1];
  }
  return pcVar1;
}

