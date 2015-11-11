#include "tracker.h"

Tracker::Tracker(){}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Tracker::Tracker(
                     //CAMERASET
                       QString INPUT_FINAL_PATH_Cameras_IN,

                     //MODEL
                       QString RadioSequenceID_String_In,
                       QVector<QString> INPUT_ModelNamesQVect_IN,
                       QString INPUT_EXTENSSS_Mesh_IN,
                       QString INPUT_EXTENSSS_Skeleton_IN,
                       QString INPUT_EXTENSSS_Skin_IN,
                       QString INPUT_EXTENSSS_Limits_IN,
                       QString INPUT_EXTENSSS_VOI_IN,

                     //ANIMATION
                       QString RadioSequenceID_String_IN,
                       QString INPUT_EXTENSSS_Motion_IN,
                       QString INPUT_FINAL_PATH_IndexCheat_IN,

                     //VIDEO_SEQUENCE
                       QString INPUT_FINAL_PATH_Video_IN,
                       QString INPUT_FINAL_PATH_IndexCheat_INN,

                     //SEQUENCE
                       QString INPUT_FINAL_PATH_IndexCheat_INNN,
                       QString RadioSequenceID_String_INN,

                     //FINGERTIPS
                       QString INPUT_FINAL_PATH_Video_INN,
                       QString INPUT_FINAL_PATH_IndexCheat_INNNN
               )
{

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        sequence = Sequence(
                                    //CAMERASET
                                      INPUT_FINAL_PATH_Cameras_IN,

                                    //MODEL
                                      RadioSequenceID_String_In,
                                      INPUT_ModelNamesQVect_IN,
                                      INPUT_EXTENSSS_Mesh_IN,
                                      INPUT_EXTENSSS_Skeleton_IN,
                                      INPUT_EXTENSSS_Skin_IN,
                                      INPUT_EXTENSSS_Limits_IN,
                                      INPUT_EXTENSSS_VOI_IN,

                                    //ANIMATION
                                      RadioSequenceID_String_IN,
                                      INPUT_EXTENSSS_Motion_IN,
                                      INPUT_FINAL_PATH_IndexCheat_IN,

                                    //VIDEO_SEQUENCE
                                      INPUT_FINAL_PATH_Video_IN,
                                      INPUT_FINAL_PATH_IndexCheat_INN,

                                    //SEQUENCE
                                      INPUT_FINAL_PATH_IndexCheat_INNN,
                                      RadioSequenceID_String_INN
                           );

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        FEAT_Skinnnnn.fingerTips = FingertipSet(
                                                    INPUT_FINAL_PATH_Video_INN,
                                                    INPUT_FINAL_PATH_IndexCheat_INNNN
                                               );
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////

        currentFrameNumberSET(0,true,true);

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //sequence.posedAnimations[0].modelSet.create_VerticesOfInterest(0);
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        CLEAR_Tracker();
        ////////////////
        ////////////////

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Tracker::CLEAR_Tracker()
{

        ///////////////////////////////////////////////////
        int totalCameras = sequence.cameraSet.totalCameras;
        ///////////////////////////////////////////////////

        ////////////////////////////////////
        ////////////////////////////////////
        FEAT_Skinnnnn.clear( totalCameras );
        ////////////////////////////////////
        ////////////////////////////////////

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Tracker::BackProject_Depth_2_PCL()
{
    int camID = sequence.cameraSet.currentCameraID;

    FEAT_Skinnnnn.BackProject_Depth_2_PCL(                            camID,
                                           sequence.cameraSet.cameras[camID].intrinsicsVec_fx_fy_cx_cy,
                                           sequence.videoSequence.currFrame_RGBD_CV,
                                           sequence.videoSequence.currFrame_DDD_RAW_CV);
}
