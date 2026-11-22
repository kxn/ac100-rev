// func mesh_wan_status_send_interval @ 004bdac4 size=148

void mesh_wan_status_send_interval(void)

{
  int iVar1;
  char local_10 [8];
  
  local_10[0] = '\0';
  mesh_db_mesh_wan_status_get(local_10);
  mesh_pkt_wan_status_request_send_to_all((int)local_10[0]);
  iVar1 = FUN_00408340(600,0,mesh_wan_status_send_interval,0,0,"mesh_wan_status_send_interval",0x856
                      );
  if ((iVar1 == -1) && (mesh_err_switch != '\0')) {
    printf("[MESH_ERROR]%s()/%d start timer error\n","mesh_wan_status_send_interval",0x859);
  }
  return;
}

