#region using
using UnrealBuildTool;
using System.Collections.Generic;
#endregion

/// <summary>
/// game target
/// </summary>
public class WorkingIsNotEasyTarget : TargetRules
{
    #region constructor
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="Target">target info</param>
    public WorkingIsNotEasyTarget(TargetInfo Target) : base(Target)
    {
        // target game and build settings
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V2;

        // extra modules
        ExtraModuleNames.AddRange(new string[] { "WorkingIsNotEasy" });
    }
    #endregion
}