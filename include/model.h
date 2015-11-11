#ifndef MODEL_H
#define MODEL_H

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QFile>
#include <QDir>

#include <QApplication>

#include <iostream>
#include <fstream>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

#include "error_manager.h"


struct BoneStruct
{
        QString         name;
        double          length;
        int             addressSeListaBones;
        int             addressSeListaSKINNING;

        QString         fatherName;
        int             fatherAddress;

        QVector<int>    childrenVector;

        bool            isUsedForSkinning;
};

struct SkeletonStruct
{
        QVector< BoneStruct >  bones;
                 BoneStruct    tempBone;
                 BoneStruct    currentBone;
                 BoneStruct    startingBone;
};

struct skinningBoneStruct
{
        QString                 name;

        Eigen::MatrixXd         bone_Start_4x1;
        Eigen::MatrixXd         bone_Leaff_4x1;
};

struct SkinningBonesSkeletonStruct
{
        QVector< skinningBoneStruct >   skinningBones;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct LimitStruct
{
        double min;
        double max;
};
struct DOFsAxes
{
    Eigen::Vector3d rotX;
    Eigen::Vector3d rotY;
    Eigen::Vector3d rotZ;
};

struct TMPLimitStruct
{
        QString                     NameBone;
        bool                        Limits_FLAG_Translate;
        QVector< bool >             Limits_FLAG_Rotate;
        QVector< LimitStruct >      LimitsDgr;
        DOFsAxes                    DofAxes;
};
struct TMPRotAxis
{
        Eigen::Vector3d rotExis;
};

struct Custom_1DoF_Axis
{
        Eigen::Vector3d dir;
        Eigen::Vector3d dir_iniV;
        Eigen::Vector3d dir_draw;
        QString         type;
        int             DOF_interModel_ID;
        LimitStruct     limitsRad;
        LimitStruct     limitsDgr;
        int             ID_se_SkinningBones;
};

struct Custom_3DoF_Axis
{
        Eigen::Vector3d             location;
        QVector< Custom_1DoF_Axis > axe;

        QString name_joint_OR_bone;

        int ID_se_Bones;
        int ID_se_SkinningBones;
};

struct RotationAxesStruct
{
        QVector< Custom_3DoF_Axis >   rotationAxes;  // DE xreiazesai 2 versions (NEW), ston palio kodika pantou to New exeis
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct TriangleStruct
{
        int vertexID_1;
        int vertexID_2;
        int vertexID_3;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DominantSkinningBone
{
    int    skinningBoneID;
    double skinningWeight;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct MeshStruct
{
        QVector< DominantSkinningBone >     vertices_dominantSkinningBone;
        QVector< Eigen::Vector3d      >     vertices;
        QVector< Eigen::Vector3d      >     verticesWeighted;
        QVector< Eigen::Vector3d      >     normals_Vertices;
        QVector< Eigen::Vector3d      >     normals_Triangles;
        QVector< TriangleStruct       >     triangles;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct SkinWegitsForVertexStruct
{
        QVector< float >      skinWeights;
        QVector< float >      skinWeights_Thresholded;
};

struct SkinStruct
{
        QVector< SkinWegitsForVertexStruct > skinnedVertices;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Model
{
public:
    Model();
    Model(      QString RadioSequenceID_String,
                QString INPUT_fileNameOhneExtension,
                QString INPUT_EXTENSSS_Mesh,
                QString INPUT_EXTENSSS_Skeleton,
                QString INPUT_EXTENSSS_Skin,
                QString INPUT_EXTENSSS_Limits,
                QString INPUT_EXTENSSS_VOI
         );
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    bool has_OnlySkin;
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    QString fileString_VOI;
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    void readMesh_OFF(   QString myFileString_Mesh     );
    void readSkeleton(   QString myFileString_Skeleton );
    void readSkin_TXT(   QString myFileString_Skin     );
    void readLimits(     QString myFileString_Limits   );

    void print_SkeletonBones();
    void print_Mesh_Vertices();
    void print_Mesh_Triangles();
    void print_SkinningWeights();
    void print_SkinningBones();
    void print_Limits();

    void compute_NORMALS();
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    QString name;
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    bool isRenderable;
    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////
    int totalSkeletonFrames;
    int totalBones;
    int totalVertices;
    int totalTriangles;
    int totalSkinningBones;
    int total_AxDOFs;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SkeletonStruct                  skeleton;
    SkinningBonesSkeletonStruct     skinningSkeleton;
    RotationAxesStruct              articulationSkel;
    MeshStruct                      mesh;
    SkinStruct                      skin;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QString INPUT_myFileString_Mesh;
    QString INPUT_myFileString_Skeleton;
    QString INPUT_myFileString_Limits;
    QString INPUT_myFileString_Skin;
    QString INPUT_myFileString_Motion;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QVector< TMPLimitStruct >   tmp_Limits;
    QVector< TMPRotAxis     >   tmp_RotAxes;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QVector< QVector<int>    >  VerticesOfInterest_Viz_Indices;
    QVector< Eigen::Vector3d >  VerticesOfInterest_Centroid;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void create_Lookup_SkinningBone_to_Bones_ID();

    void print_SkinningBoneNames();

    void create_VerticesOfInterest( int voiTYPE );
    void compute_VerticesOfInterest_Centroids();

    void test_lookup_SkinningBone_to_Bones_ID();

    void test_SkinningWeihgts_sum_to_1();

    void create_thresholded_SkinningWeights();
    void print_thresholded_SkinningWeights();

    int  find_Dominant_SkinningBone( const int vertexID ); // returns skkk
    void find_Dominant_SkinningBone( const int vertexID, int &dominant_SkinningBoneID, double &dominant_SkinningBoneCONF );

    void create_Vertices_DominantSkinningBone();
    void  print_Vertices_DominantSkinningBone();

    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    QVector< int >     lookup_SkinningBone_to_Bones_ID;

    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

    Eigen::Vector4d         centroid4D_curr;            // updated in ***Animation::transform_ModelSet_MESHES***
    void            compute_Centroid4D_curr();

    /////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////

};

#endif // MODEL_H
