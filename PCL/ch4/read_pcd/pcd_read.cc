#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>




int main() {

  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

  //sensor_msg::PointCloud2 cloud_blob;
  //pcl::io::loadPCDFile<pcl::PointXYZ>("../test_pcd.pcd", cloud_blob);
  //pcl::fromPCLPointCloud2(cloud_blob, *cloud);

  if (pcl::io::loadPCDFile<pcl::PointXYZ>("../test_pcd.pcd", *cloud) == -1) {
    PCL_ERROR("Couldn't read file test_pcd.pcd \n");
    return -1;
  }

  std::cout << "Loaded " << cloud->width * cloud->height
                         << " data points from test_pcd.pcd with the following fields: "
                         << std::endl;

  for (std::size_t i = 0; i < cloud->points.size(); i++) {
    std::cout << "    " << cloud->points[i].x
              << " "    << cloud->points[i].y
              << " "    << cloud->points[i].z  << std::endl;
  }

  return 0;
}
