; func apmngr_db_role_match @ 0x00534210 size=0x18
  534210:	24840010 	addiu	a0,a0,16
  534214:	24020001 	li	v0,1
  534218:	00821004 	sllv	v0,v0,a0
  53421c:	00451024 	and	v0,v0,a1
  534220:	03e00008 	jr	ra
  534224:	0002102b 	sltu	v0,zero,v0
