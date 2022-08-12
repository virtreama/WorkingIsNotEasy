#region using
using UnrealBuildTool;
using System.Collections.Generic;
#endregion

/// <summary>
/// editor target
/// </summary>
public class WorkingIsNotEasyEditorTarget : TargetRules
{
    #region constructor
    /// <summary>
    /// constructor
    /// </summary>
    /// <param name="Target">target info</param>
    public WorkingIsNotEasyEditorTarget(TargetInfo Target) : base(Target)
    {
        // target editor and build settings
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V2;

        // extra modules
        ExtraModuleNames.AddRange(new string[] { "WorkingIsNotEasy" });
    }
    #endregion
}