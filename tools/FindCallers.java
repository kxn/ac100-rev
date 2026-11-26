// @category AC100
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
public class FindCallers extends GhidraScript {public void run()throws Exception {for(String target:getScriptArgs()){for(Function f:currentProgram.getFunctionManager().getFunctions(true)){if(!f.getName().equals(target))continue;println("TARGET "+target+" "+f.getEntryPoint());for(Reference r:currentProgram.getReferenceManager().getReferencesTo(f.getEntryPoint())){Function caller=getFunctionContaining(r.getFromAddress());println("CALLER "+r.getFromAddress()+" "+(caller==null?"DATA":caller.getName()));}}}}}
