#region usiung
using UnrealBuildTool;
#endregion

/// <summary>
/// main
/// </summary>
public class WorkingIsNotEasy : ModuleRules
{
    #region constructor
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="Target">target rules</param>
    public WorkingIsNotEasy(ReadOnlyTargetRules Target) : base(Target)
    {
        // pch usage
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // public dependencies
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        // private dependencies
        PrivateDependencyModuleNames.AddRange(new string[] { "HeadMountedDisplay" });
    }
    #endregion
}